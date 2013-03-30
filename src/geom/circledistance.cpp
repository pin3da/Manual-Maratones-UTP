static double greatCircleDistance(double latitudeS,
double longitudeS, double latitudeF, double longitudeF,
double r)
    {
		latitudeS = Math.toRadians(latitudeS);
		latitudeF = Math.toRadians(latitudeF);
		longitudeS = Math.toRadians(longitudeS);
		longitudeF = Math.toRadians(longitudeF);
		double deltaLongitude = longitudeF - longitudeS;
		double a = Math.cos(latitudeF) * Math.sin(deltaLongitude);
		double b = Math.cos(latitudeS) * Math.sin(latitudeF);
        
		b -= Math.sin(latitudeS) * Math.cos(latitudeF) 
             * Math.cos(deltaLongitude);
        
		double c = Math.sin(latitudeS) * Math.sin(latitudeF);
        
		c += Math.cos(latitudeS) * Math.cos(latitudeF) 
             * Math.cos(deltaLongitude);
             
/*      En linea recta -> dist
        double ax = Math.cos(latitudeS) * Math.cos(longitudeS);
        double ay = Math.cos(latitudeS) * Math.sin(longitudeS);
        double az = Math.sin(latitudeS);
        double bx = Math.cos(latitudeF) * Math.cos(longitudeF);
        double by = Math.cos(latitudeF) * Math.sin(longitudeF); 
        double bz = Math.sin(latitudeF);
        double dist = r*Math.sqrt(sqr(ax-bx)+ 
        sqr(ay-by)+sqr(az-bz));*/
        
		return Math.atan(Math.sqrt(a * a + b * b) / c) * r;
	}