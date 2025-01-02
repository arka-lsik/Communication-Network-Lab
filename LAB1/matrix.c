#include<stdio.h>
int main(){
 int node;
 printf("Enter the number of node: ");
 scanf("%d",&node);
// Here e traverse the 2D array and
//taking the input from user for netork conncection.
 int i,j;
 int arr[node][node];
 for(i=1;i<=node;i++){
 for(j=1;j<=node;j++){
 printf("Is there a connection between %d and %d",i,j);
 scanf("%d",&arr[i][j]);
}
}
//Printing the Ajacency Matrix.
printf("The Ajacency matrix is:\n");
 for(i=1;i<=node;i++){
 for(j=1;j<=node;j++){
 printf("%d ",arr[i][j]);
}
printf("\n");
}
for(i=1;i<=node;i++){
 for(j=1;j<=node;j++){
 if((i==j)==0){
 printf("Enter the cost value of between %d and %d",i,j);
 scanf("%d",&arr[i][j]);
}
}
}
printf("The cost matrix is:\n");
 for(i=1;i<=node;i++){
 for(j=1;j<=node;j++){
 printf("%d ",arr[i][j]);
}
printf("\n");
}
return 0;
}
