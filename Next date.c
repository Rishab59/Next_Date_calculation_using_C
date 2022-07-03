/* --------------------------------------------------------------------
 * NEXT DATE
 * --------------------------------------------------------------------
 * Printing the next date for the given date using C programming language .
 * Uses a lot of condition-checks !
 * Conditions Like : 
 *      - Last date of a month ,
 *      - Leap year for Febrary (28 or 29 days),
 *      - End of a year
 */

// Importing required libraries 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/* Code Starts */

/* Function prototypes */

int check_leap(int year) ; 
/* User-defined function to check leap year or not */

int main_function() ;
/* Calculation doing function */

/* End of Function prototypes */

int flag = 0 ;
/* flsg is a global variable */

int check_leap(int year) // Function Declaration to check leap year
{
	
    int leap = 0 ; // intialisation of leap variable

	if(year % 4 == 0)
	{
        if(year % 100 == 0)
		{		
            if(year % 400 == 0)	
			{
				leap = 1 ; // Yes, it is a leap year .
			}

			else
			{
				leap = 0 ; // No, it is not a leap year .
			}
		}

		else
		{
			leap = 1 ; // Yes, it is a leap year .
		}
	}

	else
	{
		leap = 0 ; // No, it is not a leap year .
	}
	
    return leap ;
}


int main_function()
{
	int dd, mm, yyyy, m_n ;
	int new_d, new_m, new_y ; // to store a copy of entered date

    printf("\nEnter the current date in dd mm yyyy format \t ") ;
	scanf("%d %d %d", &dd, &mm, &yyyy) ;
	
	new_d = dd ;
	new_m = mm ;
	new_y = yyyy ;
	
	switch(mm)
	{
	    case 1 : // January
	    case 3 : // March
	    case 5 : // May
	    case 7 : // July
	    case 8 : //August
	    case 10 : //October
	    case 12 : //December
		    m_n = 31 ;  // 31 days
		    break ;
	    
        case 6 : // June
	    case 4 : //April
	    case 9 : // September
	    case 11 : //November
			m_n = 30 ;  // 30 days
		    break ;
        
        case 2 : // February
			if(check_leap(yyyy))
		    {
			    m_n = 29 ;   // 29 days
                break ;
		    }

		    else
		    {
			    m_n = 28 ;   // 28 days
                break ;
		    }

        default :
            printf("Invalid Input please maintain the format\n") ;
			flag = 1 ;
	}

	new_d++ ;

	if(new_d > m_n)
	{
		new_d = 1 ;
		new_m++ ;
		if(new_m > 12)
		{	
			new_m = 1 ;
			new_y++ ;
		}
	}

	printf("The next date is %d %d %d", new_d, new_m, new_y) ;
	return flag ;
}


int main() // Code execution starts here.
{
    char ch ;
    
	while (flag == 0) // To provide reusability
    {
        flag = main_function() ;

        printf("\nDo you want for another date \n if yes please press y \t : ") ;
        
		fflush(stdin) ; 
		/* fflush(stdin) is Predefined in stdlib.h 
		   It clears all the previous unwanted input like enter in previous scanf() */
		
		scanf("%c",&ch) ;
		printf("----------------------------------------------------------------") ;
        
		if (ch=='y')
        {
            flag = 0 ;
        }
        else 
        {
            flag = 1 ;
            printf("\nThank You !") ;
        }
    }
	return 0 ;
	getch() ;

}

// -------------- END ----------------
