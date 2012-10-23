static double getminimunrectangle(point[] p,boolean area){
  int [] ind=new int[4];
  for(int i=0;i<4;i++)
   ind[i]=-1;
  double coor_miny=Double.MAX_VALUE;
  double coor_maxy=-1e100;
  double coor_minx=Double.MAX_VALUE;
  double coor_maxx=-1e100;
  for(int i=0;i<p.length;i++){
    point a=p[i];
    if (a.y<=coor_miny){
    if (ind[2]==-1 || a.y<coor_miny || p[ind[2]].x>a.x){
      ind[2]=i;
      coor_miny=a.y;
    }
    }
    if (a.y>=coor_maxy){
    if (ind[3]==-1 || a.y>coor_maxy || p[ind[3]].x<a.x){
      ind[3]=i;
      coor_maxy=a.y;
    }
    }
    if (a.x<=coor_minx){
    if (ind[0]==-1 || a.x<coor_minx || p[ind[0]].y<a.y){
      ind[0]=i;
      coor_minx=a.x;
    }
    }
    if (a.x>=coor_maxx){
    if (ind[1]==-1 || a.x>coor_maxx || p[ind[1]].y>a.y){
      ind[1]=i;
      coor_maxx=a.x;
    }
    }
  }
  double rotated_angle=0;
  point [] calipers=new point[4];
  calipers[2]=new point(16.0,0.0);
  calipers[3]=new point(-16.0,0.0);
  calipers[0]=new point(0.0,-16.0);
  calipers[1]=new point(0.0,16.0);
  point[] edges=new point[4];
  double min=Double.MAX_VALUE;
  point[] ncalipers=new point[4];
  while(rotated_angle<=3*Math.PI/4){
    for(int i=0;i<4;i++)
      edges[i]=p[(ind[i]+1)%p.length].sub(p[ind[i]]);
    int index=0;
    double max_cos=-2;
    for(int i=0;i<4;i++){
      double val=get_cos_with_caliper(calipers[i],edges[i]);
      if (val>max_cos){
        max_cos=val;
        index=i;
      }
    }
    for(int i=0;i<4;i++)
      ncalipers[i]=calipers[i].rotate2(max_cos, 
      get_sin_with_caliper(calipers[index],edges[index]));
    for(int i=0;i<4;i++){
      double ttt=max_cos-get_cos_with_caliper(calipers[i],edges[i]);
      if (Math.abs(ttt)<eps)
        ind[i]=(ind[i]+1)%p.length;
    }
    for(int i=0;i<4;i++)
      calipers[i]=ncalipers[i];
    double value=compute(p[ind[1]],calipers[1],p[ind[0]],calipers[0],
    p[ind[3]],calipers[3],p[ind[2]],calipers[2],area);
    min=Math.min(min, value);    
    rotated_angle=rotated_angle + Math.acos(max_cos);
  }
  return min;
}
  
double 
compute(point a,point va,point b,point vb,point c,point vc,point d,
point vd,boolean area){
    point bd=intersectionbtwlines(d,d.add(vd),b,b.add(vb));
    point bc=intersectionbtwlines(b,b.add(vb),c,c.add(vc));
    point ad=intersectionbtwlines(a,a.add(va),d,d.add(vd));
    if (area)
      return ad.sub(bd).norm()* bc.sub(bd).norm();
    else
      return 2*ad.sub(bd).norm()+2*bc.sub(bd).norm();
  }
  
static double get_cos_with_caliper(point c,point v){
 return c.dot(v)/(16.0*v.norm());
}

static double get_sin_with_caliper(point c,point v){
 return Math.abs(c.cross(v))/(16.0*v.norm());
}
