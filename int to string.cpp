void _swap(char *a, char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
string int2str(int x){
    string str="";
    while(x>=1){
        str+=x%10+'0';
        x=int(x/10);
    }
    int i=0;
    int j=str.size()-1;
    while(i<j){
        _swap(&str[i],&str[j]);
        i++;
        j--;
    }
    return str;
}
