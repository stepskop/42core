#include <stdio.h>
#include <limits.h>

// Prototype of your custom ft_printf function
int ft_printf(const char *format, ...);

int main(void) {
    char c = 'A';
    char *str = "Hello, World!";
    int num = 42;
    unsigned int u_num = 42;
    int neg_num = -42;
    void *ptr = (void *)&num;

    int ret_printf, ret_ft_printf;

    int max_int = INT_MAX;
    int max_uint = UINT_MAX;
    int min_int = INT_MIN;

    printf("\n---- Character (%%c) ----\n");
    ret_printf = printf("Standard printf   : [%c]\n", c);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%c]\n", c);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%5c]\n", c);              
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5c]\n", c);          
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-5c]\n", c);             
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-5c]\n", c);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%*c]\n", 5, c);           
    ret_ft_printf = ft_printf("Custom ft_printf  : [%*c]\n", 5, c);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    


    printf("\n---- String (%%s) ----\n");
    ret_printf = printf("Standard printf   : [%s]\n", str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%s]\n", str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%.5s]\n", str);           
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5s]\n", str);      
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%20s]\n", str);           
    ret_ft_printf = ft_printf("Custom ft_printf  : [%20s]\n", str);      
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-20s]\n", str);          
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-20s]\n", str);     
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%.*s]\n", 5, str);        
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.*s]\n", 5, str);   
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-20.10s]\n", str);       
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-20.10s]\n", str);  
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);




    printf("\n---- Pointer (%%p) ----\n");
    ret_printf = printf("Standard printf   : [%p]\n", ptr);              
    ret_ft_printf = ft_printf("Custom ft_printf  : [%p]\n", ptr);         
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%20p]\n", ptr);           
    ret_ft_printf = ft_printf("Custom ft_printf  : [%20p]\n", ptr);       
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-20p]\n", ptr);          
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-20p]\n", ptr);     
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);




    printf("\n---- Decimal/Integer (%%d, %%i) ----\n");
    ret_printf = printf("Standard printf   : [%-05d]\n", num);  // '-' before '0'
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-05d]\n", num);  
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%d]\n", num);             
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d]\n", num);        
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%+d]\n", num);            
    ret_ft_printf = ft_printf("Custom ft_printf  : [%+d]\n", num);       
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [% d]\n", num);            
    ret_ft_printf = ft_printf("Custom ft_printf  : [% d]\n", num);       
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-5d]\n", num);           
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-5d]\n", num);      
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%05d]\n", num);           
    ret_ft_printf = ft_printf("Custom ft_printf  : [%05d]\n", num);      
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%*d]\n", 10, num);        
    ret_ft_printf = ft_printf("Custom ft_printf  : [%*d]\n", 10, num);   
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%.*d]\n", 5, num);        
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.*d]\n", 5, num);   
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-+10.5d]\n", num);       
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-+10.5d]\n", num);  
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%d (negative): [%d]\n", neg_num);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d (negative): [%d]\n", neg_num);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%+d (negative): [%+d]\n", neg_num);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%+d (negative): [%+d]\n", neg_num);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [% d (negative): [% d]\n", neg_num);
    ret_ft_printf = ft_printf("Custom ft_printf  : [% d (negative): [% d]\n", neg_num);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%05d (negative): [%05d]\n", neg_num);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%05d (negative): [%05d]\n", neg_num);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    


    printf("\n---- Unsigned Decimal (%%u) ----\n");
    ret_printf = printf("Standard printf   : [%u]\n", u_num);            
    ret_ft_printf = ft_printf("Custom ft_printf  : [%u]\n", u_num);       
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-5u]\n", u_num);          
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-5u]\n", u_num);     
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%05u]\n", u_num);          
    ret_ft_printf = ft_printf("Custom ft_printf  : [%05u]\n", u_num);     
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%*u]\n", 10, u_num);       
    ret_ft_printf = ft_printf("Custom ft_printf  : [%*u]\n", 10, u_num);  
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%.*u]\n", 5, u_num);       
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.*u]\n", 5, u_num);  
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-10.5u]\n", u_num);       
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-10.5u]\n", u_num);  
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    


    printf("\n---- Hexadecimal (%%x, %%X) ----\n");
    ret_printf = printf("Standard printf   : [%x]\n", num);              
    ret_ft_printf = ft_printf("Custom ft_printf  : [%x]\n", num);         
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%#x]\n", num);             
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#x]\n", num);        
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%05x]\n", num);            
    ret_ft_printf = ft_printf("Custom ft_printf  : [%05x]\n", num);       
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-10x]\n", num);           
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-10x]\n", num);      
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%.*x]\n", 5, num);         
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.*x]\n", 5, num);    
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%#-10.5x]\n", num);        
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#-10.5x]\n", num);   
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%X]\n", num);              
    ret_ft_printf = ft_printf("Custom ft_printf  : [%X]\n", num);         
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%#X]\n", num);             
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#X]\n", num);        
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%05X]\n", num);            
    ret_ft_printf = ft_printf("Custom ft_printf  : [%05X]\n", num);       
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-10X]\n", num);           
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-10X]\n", num);      
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    


    printf("\n---- Percent (%%%%) ----\n");
    ret_printf = printf("Standard printf   : [%%]\n");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%%]\n");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%5%%]\n");                 
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5%%]\n");            
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%5%%-]\n");                 
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5%%-]\n");            
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%-5%%]\n");                
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-5%%]\n");           
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    


    printf("\n---- Edge Cases ----\n");
    ret_printf = printf("Standard printf   : [%d (INT_MAX): [%d]\n", INT_MAX);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d (INT_MAX): [%d]\n", INT_MAX);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%d (INT_MIN): [%d]\n", INT_MIN);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d (INT_MIN): [%d]\n", INT_MIN);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%u (UINT_MAX): [%u]\n", UINT_MAX);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%u (UINT_MAX): [%u]\n", UINT_MAX);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: INT_MAX
    ret_printf = printf("Standard printf   : [%d (INT_MAX)]\n", max_int);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d (INT_MAX)]\n", max_int);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: INT_MIN
    ret_printf = printf("Standard printf   : [%d (INT_MIN)]\n", min_int);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d (INT_MIN)]\n", min_int);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: UINT_MAX
    ret_printf = printf("Standard printf   : [%u (UINT_MAX)]\n", max_uint);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%u (UINT_MAX)]\n", max_uint);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Negative number
    ret_printf = printf("Standard printf   : [%d (Negative)]\n", neg_num);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d (Negative)]\n", neg_num);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Zero
    ret_printf = printf("Standard printf   : [%d (Zero)]\n", 0);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d (Zero)]\n", 0);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: 0
    ret_printf = printf("Standard printf   : [%u (Zero)]\n", 0);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%u (Zero)]\n", 0);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Maximum unsigned integer
    ret_printf = printf("Standard printf   : [%u (UINT_MAX)]\n", max_uint);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%u (UINT_MAX)]\n", max_uint);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Combining flag orders
    ret_printf = printf("Standard printf   : [%#0+5u (UINT_MAX)]\n", max_uint);  // Combining flags
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#0+5u (UINT_MAX)]\n", max_uint);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Formatting negative number
    ret_printf = printf("Standard printf   : [%+d (Negative)]\n", neg_num);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%+d (Negative)]\n", neg_num);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Applying flags in different orders
    ret_printf = printf("Standard printf   : [% 0+5d (Positive)]\n", num);
    ret_ft_printf = ft_printf("Custom ft_printf  : [% 0+5d (Positive)]\n", num);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%5 d (Positive)]\n", num); // ' ' before width
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5 d (Positive)]\n", num);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    return 0;
}
