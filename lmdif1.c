#include "cminpack.h"
#include "cminpackP.h"

__cminpack_attr__
int __cminpack_func__(lmdif1)(__cminpack_decl_fcn_mn__ void *p, int m, int n, real *x, 
	real *fvec, real tol, int *iwa, 
	real *wa, int lwa)
{
    /* Initialized data */

    const real factor = 100.;

    int mp5n, mode, nfev;
    real ftol, gtol, xtol;
    real epsfcn;
    int maxfev, nprint;
    int info;

/*     ********** */

/*     subroutine lmdif1 */

/*     the purpose of lmdif1 is to minimize the sum of the squares of */
/*     m nonlinear functions in n variables by a modification of the */
/*     levenberg-marquardt algorithm. this is done by using the more */
/*     general least-squares solver lmdif. the user must provide a */
/*     subroutine which calculates the functions. the jacobian is */
/*     then calculated by a forward-difference approximation. */

/*     the subroutine statement is */

/*       subroutine lmdif1(fcn,m,n,x,fvec,tol,info,iwa,wa,lwa) */

/*     where */

/*       fcn is the name of the user-supplied subroutine which */
/*         calculates the functions. fcn must be declared */
/*         in an external statement in the user calling */
/*         program, and should be written as follows. */

/*         subroutine fcn(m,n,x,fvec,iflag) */
/*         integer m,n,iflag */
/*         double precision x(n),fvec(m) */
/*         ---------- */
/*         calculate the functions at x and */
/*         return this vector in fvec. */
/*         ---------- */
/*         return */
/*         end */

/*         the value of iflag should not be changed by fcn unless */
/*         the user wants to terminate execution of lmdif1. */
/*         in this case set iflag to a negative integer. */

/*       m is a positive integer input variable set to the number */
/*         of functions. */

/*       n is a positive integer input variable set to the number */
/*         of variables. n must not exceed m. */

/*       x is an array of length n. on input x must contain */
/*         an initial estimate of the solution vector. on output x */
/*         contains the final estimate of the solution vector. */

/*       fvec is an output array of length m which contains */
/*         the functions evaluated at the output x. */

/*       tol is a nonnegative input variable. termination occurs */
/*         when the algorithm estimates either that the relative */
/*         error in the sum of squares is at most tol or that */
/*         the relative error between x and the solution is at */
/*         most tol. */

/*       info is an integer output variable. if the user has */
/*         terminated execution, info is set to the (negative) */
/*         value of iflag. see description of fcn. otherwise, */
/*         info is set as follows. */

/*         info = 0  improper input parameters. */

/*         info = 1  algorithm estimates that the relative error */
/*                   in the sum of squares is at most tol. */

/*         info = 2  algorithm estimates that the relative error */
/*                   between x and the solution is at most tol. */

/*         info = 3  conditions for info = 1 and info = 2 both hold. */

/*         info = 4  fvec is orthogonal to the columns of the */
/*                   jacobian to machine precision. */

/*         info = 5  number of calls to fcn has reached or */
/*                   exceeded 200*(n+1). */

/*         info = 6  tol is too small. no further reduction in */
/*                   the sum of squares is possible. */

/*         info = 7  tol is too small. no further improvement in */
/*                   the approximate solution x is possible. */

/*       iwa is an integer work array of length n. */

/*       wa is a work array of length lwa. */

/*       lwa is a positive integer input variable not less than */
/*         m*n+5*n+m. */

/*     subprograms called */

/*       user-supplied ...... fcn */

/*       minpack-supplied ... lmdif */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */

/*     check the input parameters for errors. */

    if (n <= 0 || m < n || tol < 0. || lwa < m * n + n * 5 + m) {
        return 0;
    }

/*     call lmdif. */

    maxfev = (n + 1) * 200;
    ftol = tol;
    xtol = tol;
    gtol = 0.;
    epsfcn = 0.;
    mode = 1;
    nprint = 0;
    mp5n = m + n * 5;
    info = __cminpack_func__(lmdif)(__cminpack_param_fcn_mn__ p, m, n, x, fvec, ftol, xtol, gtol, maxfev,
	    epsfcn, wa, mode, factor, nprint, &nfev, &wa[mp5n],
            m, iwa, &wa[n], &wa[(n << 1)], &wa[n * 3], 
	    &wa[(n << 2)], &wa[n * 5]);
    if (info == 8) {
	info = 4;
    }
    return info;

/*     last card of subroutine lmdif1. */

} /* lmdif1_ */


__cminpack_attr__
int __cminpack_func__(lmdif1bc)(__cminpack_decl_fcn_bc_mn__ void *p, int m, int n, real *x, 
	real *fvec, const int* iuser, const real *user, real tol, int *iwa, 
	real *wa, int lwa)
{
    /* Initialized data */

    const real factor = 100.;

    int mp5n, mode, nfev;
    real ftol, gtol, xtol;
    real epsfcn;
    int maxfev, nprint;
    int info;

/*     ********** */

/*     subroutine lmdif1 */

/*     the purpose of lmdif1 is to minimize the sum of the squares of */
/*     m nonlinear functions in n variables by a modification of the */
/*     levenberg-marquardt algorithm. this is done by using the more */
/*     general least-squares solver lmdif. the user must provide a */
/*     subroutine which calculates the functions. the jacobian is */
/*     then calculated by a forward-difference approximation. */

/*     the subroutine statement is */

/*       subroutine lmdif1(fcn,m,n,x,fvec,tol,info,iwa,wa,lwa) */

/*     where */

/*       fcn is the name of the user-supplied subroutine which */
/*         calculates the functions. fcn must be declared */
/*         in an external statement in the user calling */
/*         program, and should be written as follows. */

/*         subroutine fcn(m,n,x,fvec,iflag) */
/*         integer m,n,iflag */
/*         double precision x(n),fvec(m) */
/*         ---------- */
/*         calculate the functions at x and */
/*         return this vector in fvec. */
/*         ---------- */
/*         return */
/*         end */

/*         the value of iflag should not be changed by fcn unless */
/*         the user wants to terminate execution of lmdif1. */
/*         in this case set iflag to a negative integer. */

/*       m is a positive integer input variable set to the number */
/*         of functions. */

/*       n is a positive integer input variable set to the number */
/*         of variables. n must not exceed m. */

/*       x is an array of length n. on input x must contain */
/*         an initial estimate of the solution vector. on output x */
/*         contains the final estimate of the solution vector. */

/*       fvec is an output array of length m which contains */
/*         the functions evaluated at the output x. */

/*       tol is a nonnegative input variable. termination occurs */
/*         when the algorithm estimates either that the relative */
/*         error in the sum of squares is at most tol or that */
/*         the relative error between x and the solution is at */
/*         most tol. */

/*       info is an integer output variable. if the user has */
/*         terminated execution, info is set to the (negative) */
/*         value of iflag. see description of fcn. otherwise, */
/*         info is set as follows. */

/*         info = 0  improper input parameters. */

/*         info = 1  algorithm estimates that the relative error */
/*                   in the sum of squares is at most tol. */

/*         info = 2  algorithm estimates that the relative error */
/*                   between x and the solution is at most tol. */

/*         info = 3  conditions for info = 1 and info = 2 both hold. */

/*         info = 4  fvec is orthogonal to the columns of the */
/*                   jacobian to machine precision. */

/*         info = 5  number of calls to fcn has reached or */
/*                   exceeded 200*(n+1). */

/*         info = 6  tol is too small. no further reduction in */
/*                   the sum of squares is possible. */

/*         info = 7  tol is too small. no further improvement in */
/*                   the approximate solution x is possible. */

/*       iwa is an integer work array of length n. */

/*       wa is a work array of length lwa. */

/*       lwa is a positive integer input variable not less than */
/*         m*n+5*n+m. */

/*     subprograms called */

/*       user-supplied ...... fcn */

/*       minpack-supplied ... lmdif */

/*     argonne national laboratory. minpack project. march 1980. */
/*     burton s. garbow, kenneth e. hillstrom, jorge j. more */

/*     ********** */

/*     check the input parameters for errors. */

    if (n <= 0 || m < n || tol < 0. || lwa < m * n + n * 5 + m) {
        return 0;
    }

/*     call lmdif. */

    maxfev = (n + 1) * 200;
    ftol = tol;
    xtol = tol;
    gtol = 0.;
    epsfcn = 0.;
    mode = 1;
    nprint = 0;
    mp5n = m + n * 5;
    info = __cminpack_func__(lmdifbc)(__cminpack_param_fcn_bc_mn__ p, m, n, x, fvec, 
        iuser, user, ftol, xtol, gtol, maxfev,
	    epsfcn, wa, mode, factor, nprint, &nfev, &wa[mp5n],
            m, iwa, &wa[n], &wa[(n << 1)], &wa[n * 3], 
	    &wa[(n << 2)], &wa[n * 5]);
    if (info == 8) {
	info = 4;
    }
    return info;

/*     last card of subroutine lmdif1. */

} /* lmdif1bc_ */

