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

   }
