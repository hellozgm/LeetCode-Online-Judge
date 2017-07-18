//本题要求比较繁琐，对于字符串的首字符，
//    1.如果是空格则忽略，
//    2.如果是字母则返回0，
//    3.如果是正负号，则下一个字符一定是数字才可以，否则返回0.
//还要注意判断是否超出int范围，所以用double类型的作为结果。
int myAtoi(char* str) {
    if(str == NULL)
        return 0;
    double result=0;
    char* p = str;
    bool flag = true;
    while(*p != '\0' && *p == ' ')  //忽略掉空格
        ++p;
   if(*p == '-' || *p == '+'){  //第一个字符是不是正负号
       if(*p =='-')
           flag = false;
        ++p;
        if(*p == '\0' || *p < '0' || *p > '9' )  //如果第一个正负号后面不是数字，则返回0
            return 0;
    }
    if(*p >'9' || *p <'0')  //第一个字符是其他字符，则返回0，包括'\0'
        return 0;
    while(*p != '\0' && *p >='0' && *p <= '9'){  //将字符串转化为数字
        result = result*10 + *p -'0';
        ++p;
     }
    if(!flag)
        result = -result;
    if(result > INT_MAX)  //超出int范围，则范围int类型的对应的极值
        result = INT_MAX;
    if(result < INT_MIN)
        result = INT_MIN;    
    return (int)result;  //转换类型为int
}
 
