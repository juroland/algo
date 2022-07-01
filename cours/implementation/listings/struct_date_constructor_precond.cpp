#include <gsl/gsl>

// Retourne le nombre de jours pour une année y et un mois m
int days_in_ith_month(int y, int m);

struct Date
{
    int y, m, d;
    Date(int yy, int mm, int dd): y{yy}, m{mm}, d{dd}
    {
        Expects(y >= 1 && m >= 1 && d >= 1);
        Expects(d <= days_in_ith_month(y, m));
        /* ... */
    }
};