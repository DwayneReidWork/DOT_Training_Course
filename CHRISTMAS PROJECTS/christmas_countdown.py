#Imports
from datetime import date
import os #Import to clear screen

#Constant variables
TODAY = date.today()
CHRISTMAS = date.fromisoformat("2025-12-25")

#Function to calculate time between todays date and a specific date.
def countdown(target_date):
    total_time = target_date - TODAY
    return total_time.days

os.system('cls')
print("Today's date:", TODAY)

while True:
    try:
        #Ask user what kind of countdown they would like.
        uChoice = int(input("Which would you like:\n1. A Countdown to Christmas 2025\n2. A countdown to a date of your choosing?\n\n" ))
        
    except ValueError:
        print("YOU HAVE TWO OPTIONS. TRY AGAIN!")
        continue
    
    #If statement to handle user input.
    if uChoice == 1:
        print(f"\nThere are {countdown(CHRISTMAS)} days until Christmas!!!!!\n\n")
        break
    elif uChoice == 2:
        uInputDate = input("Please enter a target date in the format YYYY-MM-DD: ")
        try:
            # Convert user input to a date object
            target_date = date.fromisoformat(uInputDate)
            #To handle dates in the past.
            if target_date < TODAY:
                print(f"\nThat date has passed and it was {-countdown(target_date)} days ago.")
            else:
                print(f"\nThere are {countdown(target_date)} days until {uInputDate}!")
            break
        #Input validation.
        except ValueError:
            print("Invalid date format! Please use the format YYYY-MM-DD.")