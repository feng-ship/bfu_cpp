#include<iostream>
#include<cmath>
using namespace std;
class VectorN
{
private:
    int dim;
    double *values;
public:
    VectorN(int d,double *v){
        dim=d;
        values=new double[dim];
        for(int i=0;i<dim;i++){
            values[i]=v[i];
        }
    }
    ~VectorN(){
        delete[] values;
    }
    double Mag(){
        double temp=0;
        for(int i=0;i<dim;i++){
            temp+=values[i]*values[i];
        }
        return sqrt(temp);
    }
};
int main()
{
    int num;
    cin >> num;
    double *dtemp = new double[num];
    for(int i=0; i<num; i++)
        cin >> dtemp[i];
    VectorN vn2(num, dtemp);
    delete[] dtemp;
    cout << vn2.Mag() <<endl;
    return 0;
}