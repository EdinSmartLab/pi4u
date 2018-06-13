typedef struct Surrogate Surrogate;

void surrogate_ini(int dim, Surrogate **s);
void surrogate_fin(Surrogate *s);

void surrogate_add_point(const double *x, double y, Surrogate *s);
void surrogate_optimize(Surrogate *s);
double surrogate_eval(const double *x, Surrogate *s);
double surrogate_error(int n, double* const* xx, const double *yyexact, Surrogate *s);
