double closestpair(ArrayList<Point> Px,ArrayList<Point> Py)
{
  if (Px.size()<=12){
    double closest=Double.MAX_VALUE;
    for(int i=0;i<Px.size();i++){
      for(int j=i+1;j<Px.size();j++){
        closest=Math.min(distance(Px.get(i), Px.get(j)),closest);
      }
    }
    return closest;
  }
  double x=Px.get(Px.size()/2).x;
  ArrayList<Point> Lx=new ArrayList<Point>();
  ArrayList<Point> Ly=new ArrayList<Point>();
  ArrayList<Point> Rx=new ArrayList<Point>();
  ArrayList<Point> Ry=new ArrayList<Point>();
  for(Point p: Px){
    if (p.x<x)
      Lx.add(p);
    else
      Rx.add(p);
  }
  for(Point p: Py){
    if (p.x<x)
      Ly.add(p);
    else
      Ry.add(p);
  }
  double d1=closestpair(Lx,Ly);
  double d2=closestpair(Rx,Ry);
  double delta=Math.min(d1,d2);
  double split=closestsplitpair(Px,Py,delta,x);
  return Math.min(delta, split);
}


static double closestsplitpair(ArrayList<Point> Px,
ArrayList<Point> Py,double delta,double x){
  ArrayList<Point> Sy=new ArrayList<Point>();
  for(Point p: Py){
    if (x-delta<p.x && p.x<x+delta)
      Sy.add(p);
  }
  double min=delta;
  for(int i=0;i<Sy.size();i++){
    for(int j=1;j<=7 && i+j<Sy.size();j++){
      min=Math.min(min, distance(Sy.get(i),Sy.get(i+j)));
    }
  }
  return min;
}