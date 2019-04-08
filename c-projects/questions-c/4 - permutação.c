#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int permutacao_matriz(int m, int n, int mat[m][n]){
	int i, j, h, c1, c0;
	for(i=0;i<n;i++){
		for(j=0, c0=0, c1=0;j<n;j++){
			if(mat[i][j]==0)
                c0++;
			else if(mat[i][j]==1) {
				c1++;
				for(h=j+1;h<n;h++){
					if(mat[i][h]==1)
						return 0;
				}
			}
			else
			return 0;
		}
		if(c0 != n-1 || c1 != 1)
            return 0;
	}
	return 1;
}

int main(){
       int matriz [3][3] = {{0,1,0}, {1,0,0}, {0,0,1}};
       int res;
  res = permutacao_matriz(3,3,matriz);

    if(res == 1)
       printf("E permutacao");
       else
        printf("Nao e permutacao");
   }
