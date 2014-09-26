       DOUBLE PRECISION FUNCTION ExpEigenVal(A, N)
       IMPLICIT NONE
       DOUBLE PRECISION A(N,N), EIG(n),WORK(N*(3+N/2))
       INTEGER N, L, INF, I 
       DOUBLE PRECISION ANS

       L = N*(3+N/2)
       CALL DSYEV('V','U', N, A, N, EIG, WORK, L, INF)

       ANS=0.0;
       DO I=1,N
          ANS=ANS+EXP(EIG(I))
       END DO
       ExpEigenVal=ANS

       END FUNCTION
