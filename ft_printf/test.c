#include <stdio.h>
#include <limits.h>

// Prototype of your custom ft_printf function
// Moulinette 125/100
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


    printf("\n---- Some basic shi ----\n");

    ret_printf = printf(NULL);
    ret_ft_printf = ft_printf(NULL);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%d, %d, %i, %i, %u]\n", 123, -456, 789, -1011, 4294967295u);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d, %d, %i, %i, %u]\n", 123, -456, 789, -1011, 4294967295u);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%x, %x, %X, %X]\n", 255, 0x123ABC, 255, 0x123ABC);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%x, %x, %X, %X]\n", 255, 0x123ABC, 255, 0x123ABC);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Test %c with characters (basic characters)
    ret_printf = printf("Standard printf   : [%c, %c, %c]\n", 'A', 'B', 'C');
    ret_ft_printf = ft_printf("Custom ft_printf  : [%c, %c, %c]\n", 'A', 'B', 'C');
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Test %% (literal percent sign)
    ret_printf = printf("Standard printf   : [%%, %%]\n");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%%, %%]\n");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    printf("\n---- NULL and Invalid Argument Tests ----\n");

    // Test %s with a NULL string
    ret_printf = printf("Standard printf   : [%s (NULL)]\n", NULL);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%s (NULL)]\n", NULL);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Test %p with a NULL pointer
    ret_printf = printf("Standard printf   : [%p (NULL)]\n", NULL);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%p (NULL)]\n", NULL);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Test %p with valid pointers
    int some_var = 42;
    ret_printf = printf("Standard printf   : [%p, %p]\n", &some_var, &ret_printf);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%p, %p]\n", &some_var, &ret_ft_printf);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);



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
    ret_printf = printf("Standard printf   : [%.s]\n", str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.s]\n", str);
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
    
    ret_printf = printf("Standard printf   : [%010.1d]\n", 874);       
    ret_ft_printf = ft_printf("Custom ft_printf  : [%010.1d]\n", 874);  
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

    ret_printf = printf("Standard printf   : [%6.5d]\n", 1689845465);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%6.5d]\n", 1689845465);
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


    char *null_str = NULL;
    ret_printf = printf("Standard printf   : [%s (NULL)]\n", null_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%s (NULL)]\n", null_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Empty string
    char *empty_str = "";
    ret_printf = printf("Standard printf   : [%s (Empty)]\n", empty_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%s (Empty)]\n", empty_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: NULL pointer (%p)
    void *null_ptr = NULL;
    ret_printf = printf("Standard printf   : [%p (NULL Pointer)]\n", null_ptr);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%p (NULL Pointer)]\n", null_ptr);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Empty pointer (%p) - pointer to something but zero value
    int *empty_ptr = (int *)0;
    ret_printf = printf("Standard printf   : [%p (Empty Pointer)]\n", empty_ptr);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%p (Empty Pointer)]\n", empty_ptr);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: NULL pointer in hex (%x)
    ret_printf = printf("Standard printf   : [%x (NULL Pointer as int)]\n", (unsigned int)null_ptr);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%x (NULL Pointer as int)]\n", (unsigned int)null_ptr);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Empty character
    ret_printf = printf("Standard printf   : [%c (Empty Char)]\n", '\0');
    ret_ft_printf = ft_printf("Custom ft_printf  : [%c (Empty Char)]\n", '\0');
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Empty format string
    ret_printf = printf("Standard printf   : [(Empty Format String)]\n");
    ret_ft_printf = ft_printf("Custom ft_printf  : [(Empty Format String)]\n");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    printf("\n---- NULL and Empty String with Flags ----\n");

    // Edge case: NULL string with width
    ret_printf = printf("Standard printf   : [%10s (NULL with width)]\n", null_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10s (NULL with width)]\n", null_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: NULL string with precision
    ret_printf = printf("Standard printf   : [%.5s (NULL with precision)]\n", null_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5s (NULL with precision)]\n", null_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Empty string with width
    ret_printf = printf("Standard printf   : [%10s (Empty with width)]\n", empty_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10s (Empty with width)]\n", empty_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: Empty string with precision
    ret_printf = printf("Standard printf   : [%.5s (Empty with precision)]\n", empty_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5s (Empty with precision)]\n", empty_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    printf("\n---- NULL Pointer with Flags ----\n");

    // Edge case: NULL pointer with width
    ret_printf = printf("Standard printf   : [%10p (NULL Pointer with width)]\n", null_ptr);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10p (NULL Pointer with width)]\n", null_ptr);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Edge case: NULL pointer with precision (pointer doesn't use precision but testing edge case)
    ret_printf = printf("Standard printf   : [%.5p (NULL Pointer with precision)]\n", null_ptr);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5p (NULL Pointer with precision)]\n", null_ptr);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    

    printf("\n---- Integer Overflow and Edge Case Tests ----\n");

    // Integer overflow: INT_MAX + 1 (technically undefined behavior, but interesting for testing)
    int overflow_int = INT_MAX + 1;
    ret_printf = printf("Standard printf   : [%d (INT_MAX + 1)]\n", overflow_int);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d (INT_MAX + 1)]\n", overflow_int);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Integer underflow: INT_MIN - 1 (technically undefined behavior)
    int underflow_int = INT_MIN - 1;
    ret_printf = printf("Standard printf   : [%d (INT_MIN - 1)]\n", underflow_int);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%d (INT_MIN - 1)]\n", underflow_int);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Unsigned integer overflow: UINT_MAX + 1
    unsigned int overflow_uint = UINT_MAX + 1;
    ret_printf = printf("Standard printf   : [%u (UINT_MAX + 1)]\n", overflow_uint);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%u (UINT_MAX + 1)]\n", overflow_uint);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);



    printf("\n---- Buffer Overflow and Large Precision Tests ----\n");

    // Large precision for string
    char *large_str = "This is a large string that is intended to overflow the buffer if not handled correctly.";
    ret_printf = printf("Standard printf   : [%.1000s (Large Precision)]\n", large_str);  // Precision far larger than string length
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.1000s (Large Precision)]\n", large_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Large width for string
    ret_printf = printf("Standard printf   : [%1000s (Large Width)]\n", large_str);  // Large width beyond typical screen size
    ret_ft_printf = ft_printf("Custom ft_printf  : [%1000s (Large Width)]\n", large_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    ret_printf = printf("Standard printf   : [%1000s (NULL with Large Width)]\n", null_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%1000s (NULL with Large Width)]\n", null_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);



    printf("\n---- Precision Flag Tests ----\n");

    // %c - Precision has no effect
    ret_printf = printf("Standard printf   : [%.2c, %.0c, %.10c]\n", 'A', 'B', 'C');
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.2c, %.0c, %.10c]\n", 'A', 'B', 'C');
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %s - Precision limits the number of characters printed
    char *test_str = "Hello, World!";
    ret_printf = printf("Standard printf   : [%.5s, %.0s, %.10s]\n", test_str, test_str, test_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5s, %.0s, %.10s]\n", test_str, test_str, test_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %p - Precision generally has no effect on pointer
    void *test_ptr = &test_str;
    ret_printf = printf("Standard printf   : [%.5p, %.0p, %.10p]\n", test_ptr, test_ptr, test_ptr);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5p, %.0p, %.10p]\n", test_ptr, test_ptr, test_ptr);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %d - Precision specifies the minimum number of digits
    ret_printf = printf("Standard printf   : [%.5d, %.0d, %.10d, %.2d]\n", 123, 0, -456, 789);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5d, %.0d, %.10d, %.2d]\n", 123, 0, -456, 789);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %i - Precision works similarly to %d
    ret_printf = printf("Standard printf   : [%.5i, %.0i, %.10i, %.2i]\n", 123, 0, -456, 789);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5i, %.0i, %.10i, %.2i]\n", 123, 0, -456, 789);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %u - Precision specifies the minimum number of digits
    ret_printf = printf("Standard printf   : [%.0u, %.0u, %.10u, %.2u]\n", 123, 0, 4294967295u, 42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.0u, %.0u, %.10u, %.2u]\n", 123, 0, 4294967295u, 42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %x - Precision specifies the minimum number of digits
    ret_printf = printf("Standard printf   : [%.5x, %.0x, %.10x, %.2x]\n", 0x123, 0, 0xABCDEF, 0x42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5x, %.0x, %.10x, %.2x]\n", 0x123, 0, 0xABCDEF, 0x42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);
	
    ret_printf = printf("Standard printf   : [%#.5x, %#.0x, %#.10x, %#.2x]\n", 0x123, 0, 0xABCDEF, 0x42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#.5x, %#.0x, %#.10x, %#.2x]\n", 0x123, 0, 0xABCDEF, 0x42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);


    // %X - Precision specifies the minimum number of digits (uppercase hexadecimal)
    ret_printf = printf("Standard printf   : [%.5X, %.0X, %.10X, %.2X]\n", 0x123, 0, 0xABCDEF, 0x42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5X, %.0X, %.10X, %.2X]\n", 0x123, 0, 0xABCDEF, 0x42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);
	
    ret_printf = printf("Standard printf   : [%#.5X, %#.0X, %#.10X, %#.2X]\n", 0x123, 0, 0xABCDEF, 0x42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#.5X, %#.0X, %#.10X, %#.2X]\n", 0x123, 0, 0xABCDEF, 0x42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %% - Precision has no effect
    ret_printf = printf("Standard printf   : [%.2%, %.0%, %.10%]\n");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.2%, %.0%, %.10%]\n");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);



    printf("\n---- Precision Flag with Width and Alignment Tests ----\n");

    // %c - Width with and without left alignment
    ret_printf = printf("Standard printf   : [%5c], [%-5c]\n", 'A', 'B');
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5c], [%-5c]\n", 'A', 'B');
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %s - Precision higher and lower than string length, with width adjustments
    test_str = "Hello";
    ret_printf = printf("Standard printf   : [%10.3s], [%-10.3s], [%10.10s], [%-10.10s]\n", test_str, test_str, test_str, test_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.3s], [%-10.3s], [%10.10s], [%-10.10s]\n", test_str, test_str, test_str, test_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %p - Width with pointer (precision generally has no effect here)
    test_ptr = &test_str;
    ret_printf = printf("Standard printf   : [%20p], [%-20p]\n", test_ptr, test_ptr);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%20p], [%-20p]\n", test_ptr, test_ptr);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %d - Precision higher and lower than the number of digits, with width adjustments
    ret_printf = printf("Standard printf   : [%10.5d], [%-10.5d], [%10.2d], [%-10.2d]\n", 123, 123, 4567, 4567);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.5d], [%-10.5d], [%10.2d], [%-10.2d]\n", 123, 123, 4567, 4567);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %i - Same as %d (signed integer) but with different precision
    ret_printf = printf("Standard printf   : [%8.3i], [%-8.3i], [%8.1i], [%-8.9i]\n", 987, 987, -654, -654);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%8.3i], [%-8.3i], [%8.1i], [%-8.9i]\n", 987, 987, -654, -654);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %u - Precision and width applied to unsigned integers
    ret_printf = printf("Standard printf   : [%10.5u], [%-10.5u], [%10.2u], [%-10.2u]\n", 987654321, 987654321, 42, 42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.5u], [%-10.5u], [%10.2u], [%-10.2u]\n", 987654321, 987654321, 42, 42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %x - Precision and width for hexadecimal values
    ret_printf = printf("Standard printf   : [%10.5x], [%-10.5x], [%10.2x], [%-10.2x]\n", 0xABC, 0xABC, 0x42, 0x42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.5x], [%-10.5x], [%10.2x], [%-10.2x]\n", 0xABC, 0xABC, 0x42, 0x42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %X - Same as %x but with uppercase hex
    ret_printf = printf("Standard printf   : [%10.5X], [%-10.5X], [%10.2X], [%-10.2X]\n", 0xABC, 0xABC, 0x42, 0x42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.5X], [%-10.5X], [%10.2X], [%-10.2X]\n", 0xABC, 0xABC, 0x42, 0x42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // %% - Precision has no effect, but width can apply
    ret_printf = printf("Standard printf   : [%5%], [%-5%]\n");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5%], [%-5%]\n");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);




    printf("\n---- Precision with Various Flags, Widths, and Values Tests ----\n");

    // --- Tests with %d (Signed Integers) ---
    
    // Width smaller than value, precision larger than value
    ret_printf = printf("Standard printf   : [%5.7d], [%-5.7d], [%05.7d], [%#5.7d], [% 5.7d]\n", 123, 123, 123, 123, 123);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5.7d], [%-5.7d], [%05.7d], [%#5.7d], [% 5.7d]\n", 123, 123, 123, 123, 123);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Width larger than value, precision smaller than value
    ret_printf = printf("Standard printf   : [%10.3d], [%-10.3d], [%010.3d], [%#10.3d], [% 10.3d]\n", 123, 123, 123, 123, 123);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.3d], [%-10.3d], [%010.3d], [%#10.3d], [% 10.3d]\n", 123, 123, 123, 123, 123);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Width smaller than value, precision smaller than value
    ret_printf = printf("Standard printf   : [%5.2d], [%-5.2d], [%05.2d], [%#5.2d], [% 5.2d]\n", 9876, 9876, 9876, 9876, 9876);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5.2d], [%-5.2d], [%05.2d], [%#5.2d], [% 5.2d]\n", 9876, 9876, 9876, 9876, 9876);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Precision zero with non-zero value
    ret_printf = printf("Standard printf   : [%.0d], [%.0d]\n", 12345, 0);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.0d], [%.0d]\n", 12345, 0);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Width larger than value, precision zero
    ret_printf = printf("Standard printf   : [%10.0d], [%-10.0d], [%010.0d], [%#10.0d], [% 10.0d]\n", 42, 42, 42, 42, 42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.0d], [%-10.0d], [%010.0d], [%#10.0d], [% 10.0d]\n", 42, 42, 42, 42, 42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Zero value with precision
    ret_printf = printf("Standard printf   : [%.5d], [%-10.5d], [%010.5d]\n", 0, 0, 0);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5d], [%-10.5d], [%010.5d]\n", 0, 0, 0);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Null value and precision with %s
    null_str = NULL;
    ret_printf = printf("Standard printf   : [%.5s], [%-10.5s], [%.0s]\n", null_str, null_str, null_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.5s], [%-10.5s], [%.0s]\n", null_str, null_str, null_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Tests with %x and %X (Hexadecimal) ---
    
    // Precision larger than the hex value, width larger and smaller than precision
    ret_printf = printf("Standard printf   : [%#10.5x], [%-#10.5x], [%#010.5x], [%#5.3x]\n", 0x1a3, 0x1a3, 0x1a3, 0x1a3);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#10.5x], [%-#10.5x], [%#010.5x], [%#5.3x]\n", 0x1a3, 0x1a3, 0x1a3, 0x1a3);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Precision smaller than hex value, width smaller than value
    ret_printf = printf("Standard printf   : [%#5.2x], [%-#5.2x], [%#05.2x]\n", 0xabcdef, 0xabcdef, 0xabcdef);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#5.2x], [%-#5.2x], [%#05.2x]\n", 0xabcdef, 0xabcdef, 0xabcdef);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Testing %X (uppercase hex) with various combinations
    ret_printf = printf("Standard printf   : [%#10.5X], [%-#10.5X], [%#010.5X], [%#5.3X]\n", 0xF0A, 0xF0A, 0xF0A, 0xF0A);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#10.5X], [%-#10.5X], [%#010.5X], [%#5.3X]\n", 0xF0A, 0xF0A, 0xF0A, 0xF0A);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Tests with %u (Unsigned Integer) ---

    // Precision larger than value, width smaller than value
    ret_printf = printf("Standard printf   : [%10.5u], [%-10.5u], [%05.5u], [%.0u]\n", 987, 987, 987, 987);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.5u], [%-10.5u], [%05.5u], [%.0u]\n", 987, 987, 987, 987);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Zero value with precision, width larger and smaller than value
    ret_printf = printf("Standard printf   : [%10.5u], [%-10.5u], [%05.5u], [%.0u]\n", 0, 0, 0, 0);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.5u], [%-10.5u], [%05.5u], [%.0u]\n", 0, 0, 0, 0);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);



    printf("\n---- Shuffled Flag, Precision, and Width Order Tests ----\n");

    // --- Tests with %d (Signed Integers) ---
    
    // Test 1: Changing the order of flags, width, and precision
    ret_printf = printf("Standard printf   : [%7.5d], [%5-7.5d], [%05.7d], [% #5.7d]\n", 123, 123, 123, 123);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%7.5d], [%5-7.5d], [%05.7d], [% #5.7d]\n", 123, 123, 123, 123);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Test 2: Using flags in different order (- 0, #) and precision before width
    ret_printf = printf("Standard printf   : [%-.5d], [%#-5.7d], [%07.5d], [%7. #5d]\n", -456, -456, -456, -456);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-.5d], [%#-5.7d], [%07.5d], [%7. #5d]\n", -456, -456, -456, -456);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Test 3: Width smaller than value, precision larger than value with flag reordering
    ret_printf = printf("Standard printf   : [%7.10d], [%-7.10d], [%#7.10d], [%07.10d]\n", 987654, 987654, 987654, 987654);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%7.10d], [%-7.10d], [%#7.10d], [%07.10d]\n", 987654, 987654, 987654, 987654);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Tests with %x (Hexadecimal) ---
    
    // Test 4: Shuffle flags and use different order of width and precision
    ret_printf = printf("Standard printf   : [%0#7.5x], [%5.7#-x], [%7#0x], [%#7x]\n", 0x1A3, 0x1A3, 0x1A3, 0x1A3);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%0#7.5x], [%5.7#-x], [%7#0x], [%#7x]\n", 0x1A3, 0x1A3, 0x1A3, 0x1A3);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Test 5: More shuffling of precision, width, and flags for hex values
    ret_printf = printf("Standard printf   : [%5-#.7x], [%0#7x], [%-5#7.3x]\n", 0xABC, 0xABC, 0xABC);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5-#.7x], [%0#7x], [%-5#7.3x]\n", 0xABC, 0xABC, 0xABC);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Tests with %u (Unsigned Integers) ---
    
    // Test 6: Reordered flags with unsigned integers
    ret_printf = printf("Standard printf   : [%7.5u], [%7-.5u], [%05.7u], [% #5.7u]\n", 123, 123, 123, 123);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%7.5u], [%7-.5u], [%05.7u], [% #5.7u]\n", 123, 123, 123, 123);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Test 7: Width, precision, and flags in random orders for zero value
    ret_printf = printf("Standard printf   : [%-.5u], [%05.5u], [% #7.0u]\n", 0, 0, 0);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-.5u], [%05.5u], [% #7.0u]\n", 0, 0, 0);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Tests with %i (Integers) ---
    
    // Test 8: Reordered flags and modifiers for integers
    ret_printf = printf("Standard printf   : [%7.5i], [%5.7i], [% 05.5i], [%# 7i]\n", -42, -42, -42, -42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%7.5i], [%5.7i], [% 05.5i], [%# 7i]\n", -42, -42, -42, -42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Tests with %p (Pointer) ---
    
    // Test 9: Shuffling flags and width for pointer values (precision does not apply to pointers)
    test_ptr = &ret_printf;
    ret_printf = printf("Standard printf   : [%#20p], [%20-#p], [%#020p]\n", test_ptr, test_ptr, test_ptr);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#20p], [%20-#p], [%#020p]\n", test_ptr, test_ptr, test_ptr);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Tests with %s (Strings) ---
    
    // Test 10: String with shuffled flags, precision, and width
    test_str = "Hello";
    ret_printf = printf("Standard printf   : [%10.5s], [%-.7s], [%10.0s], [%5-10s]\n", test_str, test_str, test_str, test_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.5s], [%-.7s], [%10.0s], [%5-10s]\n", test_str, test_str, test_str, test_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Test 11: Null string with shuffled order
    null_str = NULL;
    ret_printf = printf("Standard printf   : [%-.5s], [%7.0s], [% 10s]\n", null_str, null_str, null_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%-.5s], [%7.0s], [% 10s]\n", null_str, null_str, null_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Tests with %% (Percent Sign) ---
    
    // Test 12: Percent sign with reordered width and flags
    ret_printf = printf("Standard printf   : [%5%], [%-7%], [%05%], [% 7%]\n");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5%], [%-7%], [%05%], [% 7%]\n");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);
   



    printf("\n---- Valid Format: Width Before Precision ----\n");

    // --- Valid Test Cases (Width before Precision) ---
    
    // Width before precision (expected behavior)
    ret_printf = printf("Standard printf   : [%7.5d], [%10.3d], [%-7.5d], [%07.5d]\n", 123, 4567, 123, 456);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%7.5d], [%10.3d], [%-7.5d], [%07.5d]\n", 123, 4567, 123, 456);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Hexadecimal with valid width and precision
    ret_printf = printf("Standard printf   : [%#7.5x], [%#10.3x], [%#-7.5x], [%#07.5x]\n", 0x1A3, 0xABC, 0x1A3, 0xABC);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#7.5x], [%#10.3x], [%#-7.5x], [%#07.5x]\n", 0x1A3, 0xABC, 0x1A3, 0xABC);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Strings with valid width and precision
    ret_printf = printf("Standard printf   : [%10.5s], [%-10.5s]\n", "HelloWorld", "Hi");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.5s], [%-10.5s]\n", "HelloWorld", "Hi");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Unsigned integer with valid width and precision
    ret_printf = printf("Standard printf   : [%10.5u], [%05.7u], [%-7.5u]\n", 1234, 56789, 42);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%10.5u], [%05.7u], [%-7.5u]\n", 1234, 56789, 42);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);


    printf("\n---- Invalid Format: Precision Before Width ----\n");

    // --- Invalid Test Cases (Precision before Width) ---
    
    // Invalid: Precision before width
    ret_printf = printf("Standard printf   : [%5.7d], [%3.10d], [%5-.7d], [%5.07d] (Precision before Width)\n", 123, 4567, 123, 456);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5.7d], [%3.10d], [%5-.7d], [%5.07d] (Precision before Width)\n", 123, 4567, 123, 456);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Invalid: Precision before width for hexadecimal
    ret_printf = printf("Standard printf   : [%5.7x], [%3.10x], [%5-#.7x], [%5.07x] (Precision before Width)\n", 0x1A3, 0xABC, 0x1A3, 0xABC);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5.7x], [%3.10x], [%5-#.7x], [%5.07x] (Precision before Width)\n", 0x1A3, 0xABC, 0x1A3, 0xABC);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // Invalid: Precision before width for strings
    // TODO: invalid format
    ret_printf = printf("Standard printf   : [%.10.5s], [%.5.10s] (Precision before Width)\n", "Hello", "Hi");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.10.5s], [%.5.10s] (Precision before Width)\n", "Hello", "Hi");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);


    
    printf("\n---- Invalid Format String Tests ----\n");

    // --- Invalid Test 1: Multiple Precision Specifiers ---
    printf("Test 1: Multiple Precision Specifiers\n");
    ret_printf = printf("Standard printf   : [%7.5.3d], [%10..3d]\n", 123, 456);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%7.5.3d], [%10..3d]\n", 123, 456);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Invalid Test 2: Precision without Width ---
    printf("Test 2: Precision Without Width\n");
    ret_printf = printf("Standard printf   : [%.d], [%.0x], [%.s]\n", 123, 0xABCD, "hello");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%.d], [%.0x], [%.s]\n", 123, 0xABCD, "hello");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Invalid Test 3: Misplaced Flags ---
    printf("Test 3: Misplaced Flags\n");
    ret_printf = printf("Standard printf   : [%0-5d], [%0-#x], [% -5d]\n", 123, 0x12F, 456);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%0-5d], [%0-#x], [% -5d]\n", 123, 0x12F, 456);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Invalid Test 4: Flags with Incompatible Types ---
    printf("Test 4: Incompatible Types with Flags\n");
    ret_printf = printf("Standard printf   : [%#d], [%#u], [%+s]\n", 123, 456, "test");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%#d], [%#u], [%+s]\n", 123, 456, "test");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Invalid Test 5: Width or Precision Too Large ---
    // printf("Test 5: Width or Precision Too Large\n");
    // ret_printf = printf("Standard printf   : [%10000d], [%1000.5000d], [%1000.10000x]\n", 123, 456, 0xABCD);
    // ret_ft_printf = ft_printf("Custom ft_printf  : [%10000d], [%1000.5000d], [%1000.10000x]\n", 123, 456, 0xABCD);
    // printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Invalid Test 6: Incomplete Format Specifier ---
    printf("Test 6: Incomplete Format Specifier\n");
    ret_printf = printf("Standard printf   : [%5], [%#], [%.], [%+]\n");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5], [%#], [%.], [%+]\n");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Invalid Test 7: Mixing Multiple Format Specifiers ---
    printf("Test 7: Mixing Multiple Format Specifiers\n");
    // ret_printf = printf("Standard printf   : [%d %s %x]\n", "hello", 123, 0xABC);  // Wrong argument order
    // ret_ft_printf = ft_printf("Custom ft_printf  : [%d %s %x]\n", "hello", 123, 0xABC);  // Wrong argument order
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Invalid Test 8: Unsupported Format Specifier ---
    printf("Test 8: Unsupported Format Specifier\n");
    ret_printf = printf("Standard printf   : [%q], [%k], [%z]\n", 123, 456, 789);  // Invalid specifiers
    ret_ft_printf = ft_printf("Custom ft_printf  : [%q], [%k], [%z]\n", 123, 456, 789);  // Invalid specifiers
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Invalid Test 9: Overlapping Width and Precision ---
    printf("Test 9: Overlapping Width and Precision\n");
    ret_printf = printf("Standard printf   : [%5.5.5d], [%10..3x], [%7.0.3s]\n", 123, 0xABCD, "test");
    ret_ft_printf = ft_printf("Custom ft_printf  : [%5.5.5d], [%10..3x], [%7.0.3s]\n", 123, 0xABCD, "test");
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);

    // --- Invalid Test 10: Null Pointer with %s ---
    printf("Test 10: Null Pointer with %%s\n");
    null_str = NULL;
    ret_printf = printf("Standard printf   : [%s]\n", null_str);
    ret_ft_printf = ft_printf("Custom ft_printf  : [%s]\n", null_str);
    printf("Return values      : printf=%d, ft_printf=%d\n\n", ret_printf, ret_ft_printf);
}
