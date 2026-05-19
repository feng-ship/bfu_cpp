#include<iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
using namespace std;
void processPoints(){
    struct Point{
        double x,y,z;
        int r,g,b;
    };
    Point p[20];
    ifstream fs("points.csv");
    if(!fs){
        exit(0);
    }
    string line;
    getline(fs,line);
    int count=0;
    double sum_x=0,sum_y=0,sum_z=0;
    while(getline(fs,line)){
        stringstream ss(line);
        char ch;
        ss>>p[count].x>>ch>>p[count].y>>ch>>p[count].z>>ch>>p[count].r>>ch>>p[count].g>>ch>>p[count].b;
        sum_x+=p[count].x;
        sum_y+=p[count].y;
        sum_z+=p[count].z;
        count++;
    }
    fs.close();
    double average_x=0,average_y=0,average_z=0;
    average_x=sum_x/count;
    average_y=sum_y/count;
    average_z=sum_z/count;
    ofstream fs2("points.csv",ios::app);
    fs2<<'\n'<<fixed<<setprecision(3)<<average_x<<','<<average_y<<','<<average_z;
    fs2.close();
    ofstream fs1("points_offset.csv");
    for(int t=0;t<count;t++){
        p[t].x+=100;
        p[t].y-=50;
        fs1<<fixed<<setprecision(3)<<p[t].x<<','<<p[t].y<<','<<p[t].z<<endl;
    }
    fs1.close();
}
int main() {
    std::cout << "Point cloud in processing..." << endl;
    processPoints();
    return 0;
}