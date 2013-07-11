#version 120

uniform vec4 orientation;

void main(){
	
	//get our current vertex position so we can modify it
	vec4 pos = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
    pos= gl_Vertex;
    
    float x=pos.x;
    float y=pos.y;
    float z=pos.z;
    
    float a=orientation.x;
        float b=orientation.y;
        float c=orientation.z;
        float d=orientation.w;

    
    pos.x=(2*b*c*x + 2*a*d*x + pow(a,2)*y - pow(b,2)*y + pow(c,2)*y - pow(d,2)*y - 2*a*b*z + 2*c*d*z)/
    sqrt((pow(2*b*c*x + 2*a*d*x + pow(a,2)*y - pow(b,2)*y + pow(c,2)*y - pow(d,2)*y - 2*a*b*z +
                2*c*d*z,2) + pow(-2*a*c*x + 2*b*d*x + 2*a*b*y + 2*c*d*y + pow(a,2)*z - pow(b,2)*z -
                                   pow(c,2)*z + pow(d,2)*z,2))/
         (pow(-1 + pow(a,2)*x + pow(b,2)*x - pow(c,2)*x - pow(d,2)*x + 2*b*c*y - 2*a*d*y +
                2*a*c*z + 2*b*d*z,2) + pow(2*b*c*x + 2*a*d*x + pow(a,2)*y - pow(b,2)*y + pow(c,2)*y -
                                             pow(d,2)*y - 2*a*b*z + 2*c*d*z,2) +
          pow(-2*a*c*x + 2*b*d*x + 2*a*b*y + 2*c*d*y + pow(a,2)*z - pow(b,2)*z - pow(c,2)*z +
                pow(d,2)*z,2)));
    
    
    
    pos.y=(-2*a*c*x + 2*b*d*x + 2*a*b*y + 2*c*d*y + pow(a,2)*z - pow(b,2)*z - pow(c,2)*z + pow(d,2)*z)/
    sqrt((pow(2*b*c*x + 2*a*d*x + pow(a,2)*y - pow(b,2)*y + pow(c,2)*y - pow(d,2)*y - 2*a*b*z +
                2*c*d*z,2) + pow(-2*a*c*x + 2*b*d*x + 2*a*b*y + 2*c*d*y + pow(a,2)*z - pow(b,2)*z -
                                   pow(c,2)*z + pow(d,2)*z,2))/
         (pow(-1 + pow(a,2)*x + pow(b,2)*x - pow(c,2)*x - pow(d,2)*x + 2*b*c*y - 2*a*d*y +
                2*a*c*z + 2*b*d*z,2) + pow(2*b*c*x + 2*a*d*x + pow(a,2)*y - pow(b,2)*y + pow(c,2)*y -
                                             pow(d,2)*y - 2*a*b*z + 2*c*d*z,2) +
          pow(-2*a*c*x + 2*b*d*x + 2*a*b*y + 2*c*d*y + pow(a,2)*z - pow(b,2)*z - pow(c,2)*z +
                pow(d,2)*z,2)));
    
    pos.z=1.;
        pos.w=1.;

    
    pos.x/=2;
        pos.y/=2;
	//finally set the pos to be that actual position rendered
	gl_Position = pos;

	//modify our color
	vec4 col = gl_Color;
    gl_FrontColor =  col;	
}
