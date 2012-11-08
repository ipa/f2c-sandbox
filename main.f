C     ==================================================================
C      Main program for both examples
C     ==================================================================
      PROGRAM SANDBOX
      INTEGER	i, j, k, l, c
      INTEGER     dim_i, dim_j, dim_k, dim_l
C
      PARAMETER	(dim_i = 2, dim_j = 3, dim_k = 5, dim_l = 7)
      REAL		Y(dim_i), X(dim_i, dim_j)
      REAL        W(dim_i, dim_j, dim_k)
      REAL        V(dim_i, dim_j, dim_k, dim_l)

C     ------------------------------------------------------------------
C       Test for 1D Array (Y)
C     ------------------------------------------------------------------
      DO , i = 1, dim_i
      	Y(i) = i
  	  CONTINUE
      END DO
C
      CALL func(dim_i, SIZE(Y))
C     ------------------------------------------------------------------
C       Test for 2D Array (X)
C     ------------------------------------------------------------------
      c = 1
      DO , i = 1,dim_i
      	DO , j = 1,dim_j
      		X(i,j) = ((i-1) * 10) + (j-1)
      	CONTINUE
      	END DO
  	  CONTINUE
      END DO
C
      CALL func_2d(X, dim_i, dim_j)
C     ------------------------------------------------------------------
C       Test for 3D Array Square sized (Z)
C     ------------------------------------------------------------------
      c = 1
      DO , i = 1, dim_i
            DO , j = 1, dim_j
                  DO , k = 1, dim_k
                        c = ((i-1) * 100) + ((j-1) * 10) + (k-1)
                        W(i,j,k) = c
                  CONTINUE
                  END DO
            CONTINUE
            END DO
        CONTINUE
      END DO
C
      CALL func_3d(W, dim_i, dim_j, dim_k)
C
C     ------------------------------------------------------------------
C       Test for 4D Array Not Square sized (Z)
C     ------------------------------------------------------------------
      c = 1
      DO , i = 1, dim_i
            DO , j = 1, dim_j
                  DO , k = 1, dim_k
                        DO , l = 1, dim_l
                              c = ((i-1) * 1000) + ((j-1) * 100) 
                              c = c + ((k-1) * 10) + (l-1)
                              V(i,j,k,l) = c
                        CONTINUE
                        END DO
                  CONTINUE
                  END DO
            CONTINUE
            END DO
        CONTINUE
      END DO
C
      CALL func_4d(V, dim_i, dim_j, dim_k, dim_l)
C
C     ------------------------------------------------------------------
C       Test for 2D Array out of 3D Array (under construction)
C     ------------------------------------------------------------------
C      WRITE(*,*) "F77: Passing 2D Array out of 4D Array"
C      DO , i = 1,N
C            DO , j = 1, N
C                  WRITE(*,*) W(i, j, 1)
C            CONTINUE
C            END DO
C      CONTINUE
C      END DO
C      CALL func_2d_sub(W(N, N, 1), N*N)
C     ------------------------------------------------------------------
      END