#include <stdio.h>

void first()
{
	/*
	This function is the eratostel sieve
	it goes trough all the numbers non prime numbers
	by starting at i=2 and going in i*i
	so the numbers that have that are multiplyed
	can't be prime numbers
	*/
	int n;
	printf("Enter the number until we need to print the prime number:");
	scanf("%d",&n);
	int ciur[10000]={0};
	for(int d=2;d*d<=n;d++)
         if(ciur[d]==0)
           for(int i=d*d;i<=n;i=i+d)
             ciur[i]=1;
	//The numbers without values are prime
	//Because it didn't have any divisers
	for(int i=2;i<=n;++i)
		if(ciur[i]==0)
			printf("%d ",i);
}

int verf_prim(int n)
{
	/*Checks if a number is prime by
	 going trough all the numbers until sqrt(n)
	 and cheks if one of them divide n
	 if it does,then the number is not prime
	 */
	if(n==1) return 0;
	if(n==2) return 1;
	for(int i=2;i*i<=n;++i){
		if(n%i==0)return 0;
	}
	return 1;
}



void second()
{
	/*This function will do the b subpoint
	 *It will go trough all the array and check if the actual number
	 is less the to next one
	 if it is will verify if the sum of those number is prime
	 if none of the condition are fullfield 
	 then we will make the actual count of the maximum subsequance 0
	 and the posible start the next number in the array
	 If the actual counter number is bigger then the maximum
	 we will make the maximum the actual counter number
	 Then we will print the numbers with a for
	 from the startIndex until the startIndex + the maximum number
	 */
	int vect[10000],n;
	printf("How many numbers you want your array to have: ");
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		printf("Vector[%d]= ",i);
		scanf("%d",&vect[i]);
	}
	int actual = 0,maximum = 0,startIndex=0,maxI=0;
	//Going from the first element until the last-1
	for(int i=0;i<n-1;++i)
	{
		//making a variable sum for easier use
		int sum = vect[i]+vect[i+1];
		//verify if the sequance is increasing
		if(vect[i]<vect[i+1]){
			//we verify if the sum is prime
			//if it is we increas our actual counter
			if(verf_prim(sum)==1)
			{actual++;}
			//if it's not we reset the actual counter
			else{
				startIndex=i+1;
				actual=0;}
		}
		//if it's not we reset the actual counter
		else{
            startIndex=i+1;
            actual=0;}
		//if we have a maximum actual couner
		//we make it to be the new max
		if(actual>maximum){
			maximum=actual;
			maxI=startIndex;
		}
	}
	//we increas maximum because we increas it initialy just by one if two number are found
	maximum++;
	if(maximum==1)
		printf("There are no such subsequence!");
	else
	{
		//here we print the sequence
		printf("The lenght of the contiguous subsequence is %d\n",maximum);
		for(int i=maxI;i<maxI+maximum;i++)
			printf("%d ",vect[i]);
	}
}



int main(){
	int op;
	printf("Please chose one of the following options: ");
	scanf("%d",&op);
	if(op==1)
		first();
	else if(op==2)
			second();
	else
		return 0;
}
