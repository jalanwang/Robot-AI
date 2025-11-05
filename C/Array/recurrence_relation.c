int main() {
    
    int number;
    scanf("%d", &number);

    int fact[number];
    
    fact[0]=1;
    for(int i=1;i<=number;i++)
    {
        fact[i]=i*fact[i-1];
    }
    
    printf("%d", fact[number]);
    return 0;
}
