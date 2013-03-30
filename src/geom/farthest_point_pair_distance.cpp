

double farthest_point_pair_distance(ArrayList<Point> v){
  int index_miny=0,index_maxy=0;
  double coor_miny=Double.MAX_VALUE;
  double coor_maxy=Double.MIN_VALUE;
  for(int i=0;i<v.size();i++){
    Point a=v.get(i);
    if (a.y<coor_miny){
      index_miny=i;
      coor_miny=a.y;
    }
    if (a.y>coor_maxy){
      index_maxy=i;
      coor_maxy=a.y;
    }
  }
  double d=v.get(index_miny).sub(v.get(index_maxy)).norm();
  double rotated_angle=0;
  Point caliper_a=new Point(1.0,0.0);
  Point caliper_b=new Point(-1.0,0.0);
  while(rotated_angle<Math.PI){
  
    Point edge_a=
    v.get((index_maxy+1)%v.size()).sub(v.get(index_maxy));
    
    Point edge_b=
    v.get((index_miny+1)%v.size()).sub(v.get(index_miny));
    
    double angle_a=caliper_a.angle(edge_a);
    double angle_b=caliper_b.angle(edge_b);
    double min=Math.min(angle_a, angle_b);
    caliper_a=caliper_a.rotate(-min);
    caliper_b=caliper_b.rotate(-min);
    if (Math.abs(angle_a-min)<eps) index_maxy=(index_maxy+1)%v.size();
    if (Math.abs(angle_b-min)<eps) index_miny=(index_miny+1)%v.size();
    d=Math.max(v.get(index_miny).sub(v.get(index_maxy)).norm(),d);
    rotated_angle=rotated_angle + min;
  }
  return d;
}