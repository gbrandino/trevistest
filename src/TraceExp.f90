      RECURSIVE FUNCTION Factorial( NN ) RESULT (Fact)
      INTEGER*8 Fact
      INTEGER NN
      IF ( NN==1 ) THEN
         Fact = 1
      ELSE
         Fact = NN*Factorial(NN-1)
         END IF
      END FUNCTION





      DOUBLE PRECISION FUNCTION TraceExp(A,N,ORDER)
      IMPLICIT NONE
      INTEGER*8,EXTERNAL :: Factorial
      DOUBLE PRECISION A(N,N),Apre(N,N),C(N,N), ATEMP(N,N)
      INTEGER N, ORDER, I, J, K
      DOUBLE PRECISION ANS,TEMP
      DOUBLE PRECISION ALPHA,BETA


! The algorithm should do C_n=\frac{1}{N!}A_{n-1}* A +C_{n-1}
! where C_0=id
!       A_0=id
! and A_n=A^n
! A_{n-1} is stored in Apre

!initialization of Apre and C
      DO I=1, N 
         DO J=1, N
            IF (I==J) THEN
               Apre(I,J) = 1.0
               C(I,J) = 1.0
            ELSE
               Apre(I,J) = 0.0
               C(I,J) = 0.0
            END IF
         ENDDO 
      ENDDO

      ALPHA=1.0
      BETA=0.0
      DO K=1,ORDER
         CALL DGEMM('N','N', N, N, N, ALPHA, Apre, N, A, N, BETA , ATEMP, N)
      
         TEMP=1.0/REAL(Factorial(K),8)
         DO I=1, N
            DO J=1, N
               C(I,J)=TEMP*ATEMP(I,J)+C(I,J)
               Apre(I,J)=ATEMP(I,J)
            ENDDO
         ENDDO

       ENDDO

      ANS=0.0
      DO I=1, N
         ANS=ANS+C(I,I)
      ENDDO
      TraceExp=ANS


      END FUNCTION
