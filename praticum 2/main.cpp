#include <iostream>
#include <cmath>
class punt{
	public:
		int x, y;
		punt(int,int);
		double bereken(double,double,double,double);
};
punt::punt(int punt1,int punt2){
	x=punt1;
	y=punt2;
	//todo make formule
}
double punt::bereken(double ax,double ay,double bx,double by){
	return sqrt(pow((ax-bx),2)+pow((ay-by),2));
}
class driehoek{
	public:
	int x[3];
	int y[3];
	void setPunt(int index, punt p){x[index]=p.x; y[index]=p.y;}
	void print();
};

void driehoek::print(){
	for(int i=0;i<3;i++){
		std::cout<<"hoekpunt"<<i<<":("<< x[i]<<","<<y[i]<<")\n";
	}
	
	punt p(1,1);
	
	std::cout<<p.bereken((double)x[0],(double)y[0],(double)x[1],(double)y[1])<<"\n";
	std::cout<<p.bereken((double)x[0],(double)y[0],(double)x[2],(double)y[2])<<"\n";
	std::cout<<p.bereken((double)x[1],(double)y[1],(double)x[2],(double)y[2])<<"\n";
	
	

}

int main(int argc, char** argv) {
	punt p1(3,4);
	punt p2(8,1);
	punt p3(3,8);
	//std::cout<<p1.bereken(5,10,2,3);
	driehoek d;
	d.setPunt(0,p1);
	d.setPunt(1,p2);
	d.setPunt(2,p3);
	d.print();
	return 0;
}

