#include <math.h>

typedef struct{
    double *center_x;
    double *center_y;
    int center_num;
}CENTER;

typedef struct {
    double *real;
    double *imag;
    int w;
    int h;
}ACCU_MATRIX;

void chardiiphcode(CENTER *center, ACCU_MATRIX *accu_matrix, int min_radii, int max_radii, double *radii)
{
    double *center_x = center->center_x;
    double *center_y = center->center_y;

    double *real = accu_matrix->real;
    double *imag = accu_matrix->imag;
    int w = accu_matrix->w;

    double pi = 3.1416;
    double m, cen_phase;
    double ln_min_R, ln_max_R, d;

    int k;

    ln_min_R = log(min_radii);
    ln_max_R = log(max_radii);
    d = ln_max_R - ln_min_R;

    for (k = 0; k < center->center_num; k++)
    {
        int p = (int)(center_x[k] + center_y[k]*w);
        cen_phase = atan2(imag[p], real[p]);
        m = (cen_phase + pi) / (2*pi) * d + ln_min_R;
        radii[k] = exp(m);
    }
}
