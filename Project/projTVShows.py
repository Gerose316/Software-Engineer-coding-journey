# Name:        Gerald Garcia Urena
# Class:       CSC 110 - Spring 2024
# Assignment:  Programming Project Design
# Due Date:    March 29, 2024 11:59 PM
# Professor:   Lisa Dipipo

                                               # Program Title: Grand Opening of the TV SHOWS PROJECT


 
                                    #Description: 
# Description: The main purpose of this function is for the user to put the appropriate data for this program
# the (openfile) function checks if the data is inputted the wrong way or if the data is not availible in the same location as the program.
# it will contine to say Invalid file name, try again... until the correct data for the program is inputted.
def openfile():
    goodfile = False
    while goodfile == False:
        fname = input("Enter the name of the data file: ")
        
        try:
            # I open the file so we may read the contents of the data set
            infile = open(fname,'r')
            goodfile = True
            # this except if th file is inputted in correctly or wrong file in general
        except IOError:
            #--going ask you over and over again to put the correct file and corretly inputted into a .csv  or .txt
            print("Invalid file name, try again...")
    return infile
            #Returns the contents of the file that will be used by the getdata function 








 
                             #Description: 
#the general idea of this function is that it makes four diffrent list for this program from the data file
# What the program does   for the  diffrent lists is that they split and strip the data and filter it in to these four Lists.
#Inside the rating and title List they are both  strings formmatted lists inputted in there perspecitve lists
#while the score and year list are both integers that have scores and years from the movies in the data
 
def getData():
    infile = openfile()
    titleList = []
    ratingList = []
    yearList = []
    scoreList = []
    next(infile)
    #Next has been used in the past for my lab 5, but it is used to skip the header for the line 
    # Loop through the file to read each line
    for line in infile:
        line = line.strip()
        if line :
           data =  line.split(',')
           Title = (data[0])
           titleList.append(Title)
           Rating = (data[1])
           ratingList.append(Rating)
           Year = int(data[2])
           yearList.append(Year)
           Score = int(data[3])
           scoreList.append(Score)
    return titleList,ratingList,yearList,scoreList
    # I returned the titleList,ratingList,yearList and the scoreList for the use of other functions in this program in order to make the tv shows program


                                    #Description:
#The getChoice function prints the following choices for the user and allows the user to input the Choice that they want to pick
#if perhaps the user picks a number under 1 or over 7 or they accdentaly put a string, the function will make you try again.
# in short this function displays the menu of choices that allowes the user to pick from 7 diffrent options


def getChoice():
    print("")
    print("Please choose one of the following options:")
    print("1 -- Find all shows with a certain rating")
    print("2 -- Find the show with the highest score released in a specified range of years")
    print("3 -- Search for a show by title")
    print("4 -- Find the average score for films with a specific rating")
    print("5 -- Find all shows with a score higher than the score for a given show")
    print("6 -- Sort all lists by year and write results to a new file")
    print("7 -- Quit")
    
    choiceChips = -1
    # the choice chips are what I called the chippers are user inputted choices between 1-7 and it goes through while loop to see what the user inputted
    while choiceChips < 1 or choiceChips > 7:
        try:
            choiceChips = int(input("Choice ==> "))
            if 1 <= choiceChips <= 7:
                print("")
                return choiceChips
            else:
                print("Invalid entry - try again")
        except ValueError:
              print("Invalid entry - try again")
    
    
    
   
                                #Description:
# the purpose of this function is that once the user inputs a certain rating, it will compute all the shows assocated to that rating.
# also, for the ratingCheck function I used exception handing in where the program checks if the (Entered rating is in the list) - 
# example: if the user wanted to check (PG-13) TV Shows then all the data will print all the tv shows that are (PG-13)


def specifiedRating(titleList,ratingList,yearList,scoreList):
    title = ''
    listCounter = []
    truthTable = True
    while truthTable:
        try:
            rateFound = input("Enter rating: ")
            if rateFound not in ratingList:
                print("Invalid entry - try again")
                continue
                #I used (continue) mutiple times throughout many homeworks and labs
                # I want to point out yet again that this is from stackOverFlow Which I stated before over course of this semester

            
            
            



            for i in range(len(ratingList)):
                if rateFound == ratingList[i]:
                    title = titleList[i]
                    listCounter.append(title)

            break
            # I used a break feature before in mutiple homeworks , but I want to point out that I used this from stackOverflow
            # I used this also from my lab 5 

        except ValueError:
            print("Invalid entry - try again")


    return listCounter
    

    


                                             #Description: 
# The highYearScore Function main purpose is for the user to input a beginYear and EndYear ranges
#, and inside the ranges in between the inputted years that finds the highest score Tv shows
# this function uses a range of while loops ,for loops and list to append the [i] that can be used for another for loop

               
    
def highYearScore(titleList,ratingList,yearList,scoreList):
    print("Enter year range to search (oldest year first)")
    title = ''
    listCounter = ''
    truthTable = True
    while truthTable:

        BeginYear,EndYear = checkSecondyear(yearList)

        if BeginYear > EndYear:
            print("Second year should be after first year - try again")

        if EndYear > BeginYear:
            truthTable = False
    
                
        
    scoreKeeper = 0
    yearKeeperList = []
    for i in range (len(yearList)):
        if yearList[i] >= BeginYear and yearList[i] <= EndYear:
            yearKeeperList.append(i)
  
    scoreKeeper = yearKeeperList[0]
    
    
    # when getting to line 176 it calls the preResults function in which prepares the headers and section to display all the tv shows ranged in the 2 years inputted by the user

    for i in yearKeeperList:
        if scoreList[i] > scoreList[scoreKeeper]:
           title = titleList[i]
        
           scoreKeeper = i
        listCounter = title
         
    

        

    return listCounter     

                               

        
    
                                        #Description:
# this function is a continuation of the highYearScore FUNCTION-->
#this function is the process that allows the user to input the both BeginYear and End year
# This function check if both entry to see if the contents of the entry is
#inside thest list and any input of a "string" is a automatic trigger of the Except prompt

def checkSecondyear(yearList):
    # This function serves as a guideline to allow make sure to communicate the user to input the correct format for this function 

    while True:

        try:
            BeginYear = int(input("Year1: "))
            # line 253 ask to input Year 1 
            if BeginYear  not in yearList :
                print("Invalid year - try again")
                continue
                 #I used (continue) mutiple times throughout many homeworks and labs
                # I want to point out yet again that this is from stackOverFlow Which I stated before over course of this semester
            
            else:
                break
                # I used a break feature before in mutiple homeworks , but I want to point out that I used this from stackOverflow
                # I used this from my lab 5 
                
        except ValueError:
                    print("Invalid entry - try again")
                    
    # Lines 271- 286 is exactly the same as year 1 exception handling                 
    while True:
                    
        try:
            EndYear = int(input("Year2: "))

            if EndYear  not in yearList :

                print("Invalid year - try again")
                continue
            
            else:
                break

                
        except ValueError:
                    print("Invalid entry - try again")



    return BeginYear,EndYear
    #These return values will be used for the highYearScore Function and will use these inputs for forloop and find the years associated in the ranges of those to inputted years

  
          
                                                #Description:
# the purposE of this function is to search for the title and in turn it prints back the exact title that you searched for
# in short it is like like a google search but in a tv shows program.
# for example: if I want to search for Mad Max , then it will print the data of Mad Max

def searchTitle(titleList,ratingList,yearList,scoreList):
    listCounter = []
    counterMeasure = ''
    tableTruth = True
    while tableTruth:
            
            title = input("Enter show title: ")
            for i in range (len(titleList)):
                if title.lower() == titleList[i].lower():
                   counterMeasure = titleList[i]
                   listCounter.append(counterMeasure)
                   tableTruth = False
                   
                
            if tableTruth is True:
                    print("")
                    print("No shows meet your criteria")
                    print("")
                    tableTruth = False
    return listCounter
            





        
            
    
                                                #Description:
# This averageScore function main purpose is to input the ratings like(PG-13,TV-MA,ETC) and it will add up all the-
#scores assocated to the rating List and give an average of the score of the inputted rating.
# In short form : the program will ask for the specified rating,
#with the specified rating , it will add up all the scores up and divide it by the amount of specified rating
# to get the average data of the specifised rating

def averageScore(ratingList, scoreList):
    totalScore = 0
    showsAverage = 0
    truthTable = True
    while truthTable:
        try:
            rateAvg = input("Enter rating: ")
            if rateAvg not in ratingList:
                print("Invalid entry - try again")
                continue
                #I used (continue) mutiple times throughout many homeworks and labs
                # I want to point out yet again that this is from stackOverFlow Which I stated before over course of this semester
                

            for i in range(len(ratingList)):
                if rateAvg == ratingList[i]:
                    totalScore += scoreList[i]
                    showsAverage += 1
  
            if showsAverage > 0:
                averageTotal = round(totalScore / showsAverage, 2)
                
    

            truthTable = False
        except IndexError:
            print("Invalid entry - try again")
            
    return averageTotal, rateAvg
    #returns averageTotal, rateAvg 
            
   
                                 #Description:
# when it comes to this function the main purpose is for the title to be inputted and to compute shows that are higher in terms of score ,higher then the established inputted tv show titles
# for example if I run the program and input Gossip Girl , then it will compute tv shows that higher in score than Gossip Girl.


def higherOtherShow (titleList,ratingList,yearList,scoreList):
    titleImportance = ''
    listCounter = []
    truthTable = True
    while truthTable:
        try:
            title = input("Enter title: ")
            if title not in titleList:
                print("Invalid entry - try again")
                continue
                #I used (continue) mutiple times throughout many homeworks and labs
                # I want to point out yet again that this is from stackOverFlow Which I stated before over course of this semster
            
            for i in range (len(titleList)):
                if title == titleList[i]:
                    titleList[i] = scoreList[i]
                    score = scoreList[i]
                    

            checkHigher = False

           
                    # I used a break feature before in mutiple homeworks , but I want to point out that I used this from stackOverflow
                    # I used this for my lab 5 

                    
            
            
                
            
            
            for i in range(len(scoreList)):
                if score < scoreList[i]:
                    titleImportance = titleList[i]
                    listCounter.append(titleImportance)
                    checkHigher = True
                
            

            if not checkHigher:
                print("")
                print("No shows meet your criteria")
                          
            break   
            
                    
        except IndexError:
            print("Invalid entry - try again")
            break
    
    return listCounter  
                    
                    
                   

            
                                        #Description:
#When it comes to this function of the bubbleSortYear, I want to say that I copied the sample code from week 9 for the bubbles sort
# since I understand a completely what the buble sort does and the best sort to use for the algorithm that can sort the years in to least to greatest
#also, what ever happens to the sorting of the years is also implemented in the other list
#meaning what ever the Algorithm  does to the yearList the other List will follow behind the yearList position.

            

    #  I used a Bubble sort to sort for the file write prgoram
def bubbleSortYear(titleList, ratingList, yearList, scoreList):
    for n in range(len(yearList)- 1): 
        for i in range(1,len(yearList) - n - 1):
            # I sorted the yearList from the oldest year to youngest year
            if int(yearList[i]) > int(yearList[i + 1]):
               yearList[i], yearList[i + 1] = yearList[i + 1], yearList[i]
               titleList[i],titleList[i+1]  =  titleList[i+1],titleList[i]
               ratingList[i],ratingList[i+1]  =  ratingList[i+1],ratingList[i]
               scoreList[i],scoreList[i+1]  =  scoreList[i+1],scoreList[i]
               
    return titleList, ratingList, yearList, scoreList
     
    
           
    

                                             #Description:
# this function purpose is to perform the file write by the insturcted direction of the bubble sort
# since I filtered the data from the bubble sort the file write makes the the file come in to existence and writes
# the file from the oldest year all the way to the recent years in to a list 
 
def fileWrite(titleList, ratingList, yearList, scoreList):
    mrFile = "year-sorted-shows.csv"
    grandFile = open(mrFile, 'w')
    grandFile.write(f'Title,Rating,Year,Score\n')

    for i in range(len(titleList)):
        if i > 0:
            grandFile.write(f"{titleList[i]},{ratingList[i]},{yearList[i]},{scoreList[i]}\n")

    grandFile.close()


    return mrFile

    
    
      
    


                                                #Description:
# Now for the print Results function, I fixed my print results function SO it can be  called in main and is able to be run in full functioning
# the purpose of the function is to print the contents of the data table for each function that needs the dataset printed
#I would also Like to point for every function besides the average function and data file function each function appends the listCounter as all the titles -->
#so that the printResults function can loop under the title List

def printResults(listCounter,titleList,ratingList,yearList,scoreList):
    print("")
    print("The TV shows that meet your criteria are:\n")
    # this print ^^^^^^^^^ after the data is found 
    print("")
    print("TITLE".ljust(40), "RATING".ljust(8), "YEAR".ljust(5), "SCORE".ljust(4)) 
    for i in range(len(titleList)):
        if titleList[i] in listCounter:
            print(str(titleList[i]).ljust(40), str(ratingList[i]).ljust(8), str(yearList[i]).ljust(5), str(scoreList[i]).ljust(4))
    return
    

    
    
    



                                         #Description:
#The main function purpose is many, for starters it is reposnsible for calling the calling the printResults function and the specific functions that compute
#the data for the print results fnction. also the function that is assocated with the 7 choices returns the choices so we can use for the while loop
# In addition the main checks if the choices  is over 7 or under 1 and if it is, it prints the "Error in your choice" prompt.


#inside the while loop  each section except for 4 and 6 all have a print results function called, in where it prints the contents of the function, that is called inside the main function
#I would like to point out that everything that has to do with printing the final result is inside the main function
def main():
    titleList,ratingList,yearList,scoreList = getData()
    choiceChips = getChoice()
    while choiceChips != 7:
        if choiceChips == 1:
            listCounter = specifiedRating(titleList,ratingList,yearList,scoreList)
            printResults(listCounter,titleList,ratingList,yearList,scoreList)
            choiceChips = getChoice()
            
        elif choiceChips == 2:
            listCounter = highYearScore(titleList,ratingList,yearList,scoreList)
            printResults(listCounter,titleList,ratingList,yearList,scoreList)

            choiceChips = getChoice()
            
        elif choiceChips == 3:
            listCounter = searchTitle(titleList,ratingList,yearList,scoreList)
            if listCounter:
                printResults(listCounter,titleList,ratingList,yearList,scoreList)
            choiceChips = getChoice()
            
        elif choiceChips == 4:
            averageTotal, rateAvg = averageScore(ratingList, scoreList)
            print(f"The average score for shows with a {rateAvg} rating is  {averageTotal}")
            choiceChips = getChoice()
            
        elif choiceChips == 5:
            listCounter = higherOtherShow(titleList,ratingList,yearList,scoreList)
            if listCounter:
                printResults(listCounter,titleList,ratingList,yearList,scoreList)
            choiceChips = getChoice()
            
        elif choiceChips == 6:
            titleList, ratingList, yearList, scoreList = bubbleSortYear(titleList, ratingList, yearList, scoreList)
            mrFile = fileWrite(titleList, ratingList, yearList, scoreList)
            print(f"Data sorted by years written to file {mrFile}")
            safeGuard = True
            choiceChips = getChoice()
            
        else:
            print("Error in your choice")
            choiceChips = getChoice()
            
    print("Good-bye")
