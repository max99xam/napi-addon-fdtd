#include <vector>
#include <napi.h>
#include <math.h>

using namespace std;
class FDTD_2D
{
    size_t ticks;
    const double PI = 3.141592653;  

     // Constants
    double aa1;  //??
    double Ti;   //??
    double tMax; //??

    // Grid size.
    static const size_t Nx = 800;

    // Source position.
    static const size_t Ny = 200;

    // Grid steps.
    double dx;
    double dt;

    //epsilon - the dielectric constant
    double eps[Nx];

    //magnetic field strength
    double Hy[Nx];
    double Hy_prev[Nx];


    //electric field strength
    double Ex[Nx];
    double Ex_prev[Nx];

    // Normalized light speed in Gaussian system.
    double c0 = 0.3;

    // lambda - wave length
    double lambda;

    // tau - pulse duration
    double tau;

    // refractive index
    double refractive_index;


    // Moor`s boundary condition.
    void BoundaryConditionsFirst();

    // Moor`s boundary condition.
    void BoundaryConditionsSecond();

    // Updating values for new time layer.
    void Calculation();



public:
    FDTD_2D(double lambda, double tau, double refractive_index);

    //double lambda, double tau, double refractive_index
    void setParams();

    // Getters.
    size_t GetNx();
    double GetLambda();
    double GetTau();
    double GetRefractiveIndex();

    // Setters.
    void setLambda(double l) { lambda = l; }
    void setTau(double t) { tau = t; }
    void setRefractiveIndex(double n) { refractive_index = n; }

    size_t GetCurrentTick();

    //start calculation
    void CalcNextLayer( std::vector<double> &vectX,
                        std::vector<double> &vectEx,
                        std::vector<double> &vectHy);
};

