#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
	float x,y;
	void InpPoint(float x1, float y1){
		x = x1;
		y = y1;
	}
	void OutPoint(){
		cout<<x<<" "<<y<<endl;
	}
	float getabcissa(){
		return x;
	}
	float getordinate(){
		return y;
	}
};

class Region
{
public:
	Point origin; //here origin is the reference point for the shape
				  // overall origin is (0,0)
	void InpOrigin(float x1, float y1){
		origin.InpPoint(x1,y1);
	}
	void OutOrigin(){
		origin.OutPoint();
	}
	float get_centre_x()
	{
		return origin.getabcissa();
	}
	float get_centre_y(){
		return origin.getordinate();
	}
	virtual int contains(float x, float y){return 0;}
	virtual void translate(float x, float y){}
	virtual void rotate(float angle){}// (x,y) is point to check
};

class Circle : public Region
{
	float radius;
public:
	void getradius(float r)
	{
		this->radius = r;
	}
	int contains(float x, float y){//point on circumference of circle is considered inside the region		

		if((x-get_centre_x())*(x-get_centre_x()) + (y-get_centre_y())*(y-get_centre_y()) <= radius*radius)
			return 1;

		else
			return 0;
	}	
	void translate(float x, float y)
	{
		(this->origin).InpPoint(get_centre_x()+x,get_centre_y()+y);
		// cout<<origin.x<<" "<<origin.y<<endl;
	}
	void rotate(float angle)
	{// rotate region(here centre) by angle theta in anti-clockwise dirn.
		(this->origin).InpPoint(cos(angle)*get_centre_x() - sin(angle)*get_centre_y(), sin(angle)*get_centre_x() + cos(angle)*get_centre_y());
		// cout<<get_centre_x()<<" "<<get_centre_y()<<endl;
	}
};

class Triangle : public Region
{
	Point a,b,c;
public:
	void Inpsides(float x1,float y1,float x2,float y2,float x3,float y3)
	{
		(this->a).InpPoint(x1,y1); (this->origin).InpPoint(x1,y1);
		(this->b).InpPoint(x2,y2);
		(this->c).InpPoint(x3,y3);
	}
	float area(float x1, float y1, float x2, float y2, float x3, float y3) 
	{ 
	   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
	}
	int contains(float x, float y)
	{
		float A = area ((this->a).getabcissa(), (this->a).getordinate(), (this->b).getabcissa(), (this->b).getordinate(), (this->c).getabcissa(),(this->c).getordinate()); 
	    float A1 = area (x,y, b.getabcissa(), b.getordinate(), (this->c).getabcissa(),(this->c).getordinate()); 
        float A2 = area ((this->a).getabcissa(), (this->a).getordinate(), x,y, (this->c).getabcissa(),(this->c).getordinate()); 
	    float A3 = area ((this->a).getabcissa(), (this->a).getordinate(), (this->b).getabcissa(), (this->b).getordinate(), x,y); 
	  
	    if(A == A1 + A2 + A3){
			// cout<<"Point is inside the triangle\n";
			return 1;
		}
		else{
			// cout<<"Point is outside the triangle\n";
			return 0;
		}
	}
	void translate(float x, float y)
	{
		(this->a).InpPoint((this->a).getabcissa()+x,(this->a).getordinate()+y);  (this->origin).InpPoint(get_centre_x()+x,get_centre_y()+y);
		(this->b).InpPoint((this->b).getabcissa()+x,(this->b).getordinate()+y);
		(this->c).InpPoint((this->c).getabcissa()+x,(this->c).getordinate()+y);
	}
	void rotate(float angle)
	{
		(this->origin).InpPoint(cos(angle)*(this->a).getabcissa()- sin(angle)*(this->a).getordinate(), sin(angle)*(this->a).getabcissa() + cos(angle)*(this->a).getordinate());
		(this->a).InpPoint(cos(angle)*(this->a).getabcissa()- sin(angle)*(this->a).getordinate(), sin(angle)*(this->a).getabcissa() + cos(angle)*(this->a).getordinate());
		(this->b).InpPoint(cos(angle)*(this->b).getabcissa()- sin(angle)*(this->b).getordinate(), sin(angle)*(this->b).getabcissa() + cos(angle)*(this->b).getordinate());
		(this->c).InpPoint(cos(angle)*(this->c).getabcissa()- sin(angle)*(this->c).getordinate(), sin(angle)*(this->c).getabcissa() + cos(angle)*(this->c).getordinate());	
	}
};

class Rectangle : public Region
{
public:
	Point a,b,c,d;
	void Inpsides(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
	{
		(this->a).InpPoint(x1,y1); (this->origin).InpPoint(x1,y1);
		(this->b).InpPoint(x2,y2);
		(this->c).InpPoint(x3,y3);
		(this->d).InpPoint(x4,y4);
	}
	float area(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) 
	{ 
	   return abs((x1*y2+x2*y3+x3*y4+x4*y1-x2*y1-x3*y2-x4*y3-x1*y4)/2);
	}
	int contains(float x, float y)
	{
	    float A = area ((this->a).getabcissa(), (this->a).getordinate(), (this->b).getabcissa(), (this->b).getordinate(), (this->c).getabcissa(),(this->c).getordinate(), (this->d).getabcissa(), (this->d).getordinate()); 
	    float A1 = area (x,y, b.getabcissa(), b.getordinate(), (this->c).getabcissa(),(this->c).getordinate(), (this->d).getabcissa(), (this->d).getordinate()); 
        float A2 = area ((this->a).getabcissa(), (this->a).getordinate(), x,y, (this->c).getabcissa(),(this->c).getordinate(), (this->d).getabcissa(), (this->d).getordinate()); 
	    float A3 = area ((this->a).getabcissa(), (this->a).getordinate(), (this->b).getabcissa(), (this->b).getordinate(), x,y, (this->d).getabcissa(), (this->d).getordinate()); 
	    float A4 = area ((this->a).getabcissa(), (this->a).getordinate(), (this->b).getabcissa(), (this->b).getordinate(), (this->c).getabcissa(),(this->c).getordinate(), x,y); 
	    if(A == (A1 + A2 + A3 + A4)/2){
			// cout<<"Point is inside the Rectangle\n";
			return 1;
		}
		else{
			// cout<<"Point is outside the Rectangle\n";
			return 0;
		}
	}
	void translate(float x, float y)
	{
		(this->a).InpPoint((this->a).getabcissa()+x,(this->a).getordinate()+y);  (this->origin).InpPoint(get_centre_x()+x,get_centre_y()+y);
		(this->b).InpPoint((this->b).getabcissa()+x,(this->b).getordinate()+y);
		(this->c).InpPoint((this->c).getabcissa()+x,(this->c).getordinate()+y);
		(this->d).InpPoint((this->d).getabcissa()+x,(this->d).getordinate()+y);
	}
	void rotate(float angle)
	{
		(this->origin).InpPoint(cos(angle)*(this->a).getabcissa()- sin(angle)*(this->a).getordinate(), sin(angle)*(this->a).getabcissa() + cos(angle)*(this->a).getordinate());
		(this->a).InpPoint(cos(angle)*(this->a).getabcissa()- sin(angle)*(this->a).getordinate(), sin(angle)*(this->a).getabcissa() + cos(angle)*(this->a).getordinate());
		(this->b).InpPoint(cos(angle)*(this->b).getabcissa()- sin(angle)*(this->b).getordinate(), sin(angle)*(this->b).getabcissa() + cos(angle)*(this->b).getordinate());
		(this->c).InpPoint(cos(angle)*(this->c).getabcissa()- sin(angle)*(this->c).getordinate(), sin(angle)*(this->c).getabcissa() + cos(angle)*(this->c).getordinate());	
		(this->d).InpPoint(cos(angle)*(this->d).getabcissa()- sin(angle)*(this->d).getordinate(), sin(angle)*(this->d).getabcissa() + cos(angle)*(this->d).getordinate());	
	}
};

class Union: public Region{
public:
	Region *R1,*R2;
	Union(Region *r1, Region *r2):R1{r1},R2{r2}{};
	int contains(float x, float y){
		return (this->R1->contains(x,y) || this->R2->contains(x,y));
	}
	void rotate(float angle){
		this->R1->rotate(angle);
		this->R2->rotate(angle);
	}
	void translate(float trans_x, float trans_y){
		this->R1->translate(trans_x,trans_y);
		this->R2->translate(trans_x,trans_y);
	}
};

class Complement: public Region{
public:
	Region *R1;
	Complement(Region *r1): R1{r1}{};
	int contains(float x, float y){
		return !(this->R1->contains(x,y));
	}
	void rotate(float angle){
		this->R1->rotate(angle);
	}
	void translate(float trans_x, float trans_y){
		this->R1->translate(trans_x,trans_y);
	}	
};

class Intersection : public Region{
public:
	Region *R1, *R2;
	Intersection(Region *r1, Region *r2): R1{r1}, R2{r2}{};
	int contains(float x, float y){
		return this->R1->contains(x,y)&&this->R2->contains(x,y);
	}
	void rotate(float angle){
		this->R1->rotate(angle);
		this->R2->rotate(angle);
	}
	void translate(float trans_x, float trans_y){
		this->R1->translate(trans_x,trans_y);
		this->R2->translate(trans_x,trans_y);
	}
};

void circle_Driver() //Driver function for shape circle
{
	Region *reg;
	Circle circ; 
	reg = &circ;
	Point check,check1;
	reg->InpOrigin(3,5);
	check.InpPoint(1,5);
	check1.InpPoint(0,12);
	circ.getradius(6.5);

	cout<<"*** For a circle with center (3,5) and radius = 6.5 units ***"<<endl;
	cout<<"Checking for point A(1,5) and (0,12)\n"<<endl;
	cout<<"Reference point is "<<reg->get_centre_x()<<" "<<reg->get_centre_y()<<endl;
	cout<<"Point A is "<<reg->contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg->contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		

	reg->translate(-1,-1); 
	cout<<"Translating by (-1,-1) =====>\n"<<endl;

	cout<<"New reference point is "<<reg->get_centre_x()<<" "<<reg->get_centre_y()<<endl;
	cout<<"Point A is "<<reg->contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg->contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		

	reg->rotate(M_PI/4);
	cout<<"Rotating by pi/4 =====>\n"<<endl;
	cout<<"New reference point is "<<reg->get_centre_x()<<" "<<reg->get_centre_y()<<endl;
	cout<<"Point A is "<<reg->contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg->contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		
}

void Triangle_Driver()
{
	Region *reg;
	Triangle tri;
	reg = &tri;
	Point check,check1;

	reg->InpOrigin(2,3);
	tri.Inpsides(2,3,4,10,6,5);
	
	check.InpPoint(5,7);
	check1.InpPoint(1,1);
	cout<<"*** For a Triangle with points as (2,3), (4,10) and (6,5) ***"<<endl;
	cout<<"Checking for point A(5,7) and B(1,1)\n"<<endl;
	cout<<"Reference point is "<<reg->get_centre_x()<<" "<<reg->get_centre_y()<<endl;
	cout<<"Point A is "<<reg->contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg->contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		

	reg->translate(1,1);
	cout<<"Translating by (-1,-1) =====>\n"<<endl;
	cout<<"New reference point is "<<reg->get_centre_x()<<" "<<reg->get_centre_y()<<endl;
	cout<<"Point A is "<<reg->contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg->contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		

	reg->rotate(-25);
	cout<<"Rotating by -25 radians =====>\n"<<endl;
	cout<<"New reference point is "<<reg->get_centre_x()<<" "<<reg->get_centre_y()<<endl;
	cout<<"Point A is "<<reg->contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg->contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		
}

void Rectangle_Driver()
{
	Region *reg;
	Rectangle rect;
	reg = &rect;
	Point check,check1;
	reg->InpOrigin(4,5);
	rect.Inpsides(3,4,4,5,5,4,4,3);
	
	check.InpPoint(4,4);
	check1.InpPoint(0,4);
	cout<<"*** For a Rectangle with points as (3,4), (4,5), (5,4) and (4,3) ***"<<endl;
	cout<<"Checking for point A(4,4) and B(0,4)\n"<<endl;
	cout<<"Reference point is "<<reg->get_centre_x()<<" "<<reg->get_centre_y()<<endl;
	cout<<"Point A is "<<reg->contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg->contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		

	reg->translate(-0.5,-0.5);
	cout<<"Translating by (-0.5,-0.5) =====>\n"<<endl;
	// cout<<"New reference point is "<<reg->get_centre_x()<<" "<<reg->get_centre_y()<<endl;
	cout<<"Point A is "<<reg->contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg->contains(check1.getabcissa(), check1.getordinate())<<endl;			
	cout<<endl;

	reg->rotate(M_PI/4);
	cout<<"Rotating by pi/4 radians =====>\n"<<endl;
	// cout<<"New reference point is "<<reg->get_centre_x()<<" "<<reg->get_centre_y()<<endl;
	cout<<"Point A is "<<reg->contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg->contains(check1.getabcissa(), check1.getordinate())<<endl;			
	cout<<endl;	
}

void complement_of_circle_driver()
{
	Region *reg1;
	Circle circ; reg1=&circ;
	Point check, check1;
	check.InpPoint(3,5); check1.InpPoint(0,12);
	reg1->InpOrigin(3,5); circ.getradius(6.5);
	Complement reg{&circ};

	cout<<"*** Complement of a Circle ***"<<endl;
	cout<<"Checking for Point A(3,5) and B(0,12)\n"<<endl;
	cout<<"Point A is "<<reg.contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg.contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		

	reg.translate(-1,-1);
	cout<<"Translating by (-1,-1) =====>\n"<<endl;
	
	cout<<"Point A is "<<reg.contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg.contains(check1.getabcissa(), check1.getordinate())<<endl;			
	cout<<endl;

	reg.rotate(M_PI/4);
	cout<<"Rotating by pi/4 radians =====>\n"<<endl;
	
	cout<<"Point A is "<<reg.contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg.contains(check1.getabcissa(), check1.getordinate())<<endl;			
	cout<<endl;	
}

void l_shaped_driver()
{
	Region *reg1, *reg2;
	Rectangle rect1, rect2;
	Point check,check1;
	check.InpPoint(7,8); check1.InpPoint(-2.7,9.9);
	reg1 = &rect1;reg2 = &rect2;
	reg1->InpOrigin(3,7); reg2->InpOrigin(6,7);
	rect1.Inpsides(3,7,6,7,6,12,3,12);	rect2.Inpsides(6,7,6,10,8,10,8,7);
	Union reg{&rect1,&rect2};
	
	cout<<"*** L_SHAPE ***"<<endl;
	cout<<"Checking for Point A(7,8) and B(-2.7,9.9)\n"<<endl;
	cout<<"Point A is "<<reg.contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg.contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		

	reg.translate(-1,-1);
	cout<<"Translating by (-1,-1) =====>\n"<<endl;
	
	cout<<"Point A is "<<reg.contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg.contains(check1.getabcissa(), check1.getordinate())<<endl;			
	cout<<endl;

	reg.rotate(M_PI/4);
	cout<<"Rotating by pi/4 radians =====>\n"<<endl;
	
	cout<<"Point A is "<<reg.contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg.contains(check1.getabcissa(), check1.getordinate())<<endl;			
	cout<<endl;	
}

void Annulus_driver()
{
	Region *reg1, *reg2;
	Circle circ1, circ2; 
	reg1 = &circ1; reg2 = &circ2;
	Point check,check1;
	reg1->InpOrigin(5,5); reg2->InpOrigin(5,5);
	circ1.getradius(6.5); circ2.getradius(3);
	check.InpPoint(4,5); check1.InpPoint(9,5);
	Complement comp{&circ2};
	Intersection reg{&circ1, &comp};

	cout<<"*** Annulus ***"<<endl;
	cout<<"Checking for Point A(4,5) and B(9,5)\n"<<endl;
	cout<<"Point A is "<<reg.contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg.contains(check1.getabcissa(), check1.getordinate())<<endl;
	cout<<endl;		

	reg.translate(-1,-1);
	cout<<"Translating by (-1,-1) =====>\n"<<endl;
	
	cout<<"Point A is "<<reg.contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg.contains(check1.getabcissa(), check1.getordinate())<<endl;			
	cout<<endl;

	reg.rotate(M_PI/4);
	cout<<"Rotating by pi/4 radians =====>\n"<<endl;
	
	cout<<"Point A is "<<reg.contains(check.getabcissa(), check.getordinate())<<endl;
	cout<<"Point B is "<<reg.contains(check1.getabcissa(), check1.getordinate())<<endl;			
	cout<<endl;	
}

int main()
{
	circle_Driver();
	Triangle_Driver();
	Rectangle_Driver();
	// Square is an special case of rectangle. So no need to write any extra code for square
	complement_of_circle_driver();
	l_shaped_driver();
	Annulus_driver();
	
	return 0;
}