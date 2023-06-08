#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int coins=0;
    if(amount>=1000){
        int temp=(amount/1000);
        coins+=temp;
        amount-=(temp*1000);
    }
     if(amount>=500){
        int temp=(amount/500);
        coins+=temp;
        amount-=(temp*500);
    }
     if(amount>=100){
        int temp=(amount/100);
        coins+=temp;
        amount-=(temp*100);
    }
     if(amount>=50){
        int temp=(amount/50);
        coins+=temp;
        amount-=(temp*50);
    }
    if(amount>=20){
        int temp=(amount/20);
        coins+=temp;
        amount-=(temp*20);
    }
     if(amount>=10){
        int temp=(amount/10);
        coins+=temp;
        amount-=(temp*10);
    }
     if(amount>=5){
        int temp=(amount/5);
        coins+=temp;
        amount-=(temp*5);
    }
     if(amount>=2){
        int temp=(amount/2);
        coins+=temp;
        amount-=(temp*2);
    }
     if(amount>=1){
        int temp=(amount/1);
        coins+=temp;
        amount-=(temp*1);
    }
    return coins;
    //The above code beats 99.68% peoples.
    // Write your code here
    //The below code is giving the wrong output.
    //I have tried but don't know why the error is coming.
    // int coins=0;
    // int deno[]={1000,500,200,100,50,20,10,5,2,1};
    //     int i=0;
    //     while(amount&&i<10){
    //       if (amount >= deno[i]) {
    //         int temp = (amount / deno[i]);
    //         coins += temp;
    //         amount -= (temp * deno[i]);
    //       }
    //         i++;
    //     }
    //     return coins;
}
