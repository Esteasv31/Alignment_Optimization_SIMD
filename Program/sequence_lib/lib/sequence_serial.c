#include <stdio.h>
#include <string.h>

#define max(a, b, c) (((a) < (b)) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
#define min(a, b, c) (((a) < (b)) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MISS -1
#define MATCH 1
#define GAP -2

int checkmatch(char x, char y){
    if (x == y){
        return MATCH;
    }else{
        return MISS;
    }
}

void getMinimumPenalty(char *x, char *y){

    int i, j;

    int m = strlen(x);
    int n = strlen(y);

    int dp[m+1][n+1];

    for (i = 0; i<(m+1); i++){
        for (j = 0; j<(n+1); j++)
            dp[i][j] = 0;
    }

    for (i = 0; i <= (m); i++){
        dp[i][0] = i * GAP;
    }

    for (i = 0; i <= (n); i++){
        dp[0][i] = i * GAP;
    }

    for (i = 1; i <= m; i++){
        for (j = 1; j <= n; j++){
            if (x[i - 1] == y[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = max((dp[i - 1][j - 1] + checkmatch(x[i], y[j])), (dp[i - 1][j] + GAP), (dp[i][j - 1] + GAP));
            }
        }
    }

    // Reconstructing the solution
    int l = n + m; // maximum possible length

    i = m; j = n;

    int xpos = l;
    int ypos = l;

    // Final answers for the respective strings
    int xans[l+1], yans[l+1];

    while ( !(i == 0 || j == 0)){
        if (x[i - 1] == y[j - 1]){
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)y[j - 1];
            i--; j--;
        }else if (dp[i - 1][j - 1] + checkmatch(x[i], y[j]) == dp[i][j]){
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)y[j - 1];
            i--; j--;
        }else if (dp[i - 1][j] + GAP == dp[i][j]){
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)'_';
            i--;
        }else if (dp[i][j - 1] + GAP == dp[i][j]){
            xans[xpos--] = (int)'_';
            yans[ypos--] = (int)y[j - 1];
            j--;
        }
    }

    while (xpos > 0){
        if (i > 0) xans[xpos--] = (int)x[--i];
        else xans[xpos--] = (int)'_';
    }

    while (ypos > 0){
        if (j > 0) yans[ypos--] = (int)y[--j];
        else yans[ypos--] = (int)'_';
    }

    // Since we have assumed the answer to be n+m long,
    // we need to remove the extra gaps in the starting
    // id represents the index from which the arrays
    // xans, yans are useful
    int id = 1;

    for (i = l; i >= 1; i--){
        if ((char)yans[i] == '_' && (char)xans[i] == '_'){
            id = i + 1;
            break;
        }
    }

    // Printing the final answer
    printf("Minimum Penalty in aligning the genes = ");
    printf("%d\n",  dp[m+1][n+1]);
    printf( "The aligned genes are :\n" );

    for (i = id; i <= l; i++){
        printf("%c", (char)xans[i]);
    }

    printf("\n");

    for (i = id; i <= l; i++){
        printf("%c", (char)yans[i]);
    }

    printf("\n");

    for (i = 0; i<(m+1); i++){
        for (j = 0; j<(n+1); j++)
            printf("%d ", dp[i][j]);
        printf("\n");
    }

    printf("\n");

    return;
}

// Driver code
int main(){
    // input strings

//    char *gene1 = "CGATGCTAGCGTATCGTAGTCTATCGTAC";
//    char *gene2 = "ACGATGCTAGCGTTTCGTATCATCGTA";

    char *gene1 = "FTFTALILLAVAV";
    char *gene2 = "FTALLLAAVTFLA";

    // calling the function to calculate the result
    getMinimumPenalty(gene1, gene2);
    return 0;
}