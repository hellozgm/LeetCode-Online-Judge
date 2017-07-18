int myAtoi(char* str) {
    if(str == NULL)
        return 0;
    double result=0;
    char* p = str;
    bool flag = true;
    while(*p != '\0' && *p == ' ')
        ++p;
   if(*p == '-' || *p == '+'){
       if(*p =='-')
           flag = false;
        ++p;
        if(*p == '\0' || *p < '0' || *p > '9' )
            return 0;
    }
    if(*p >'9' || *p <'0')
        return 0;
    if(*p == '\0')
        return 0;
    while(*p != '\0' && *p >='0' && *p <= '9'){
        result = result*10 + *p -'0';
        ++p;
     }
    if(!flag)
        result = -result;
    if(result > INT_MAX)
        result = INT_MAX;
    if(result < INT_MIN)
        result = INT_MIN;    
    return (int)result;
}
 
