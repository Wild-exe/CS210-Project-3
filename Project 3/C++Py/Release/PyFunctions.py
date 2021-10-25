import string
from collections import Counter

def DisplayQuantityList():                                              # Prints Counter sub dict to terminal from Input.txt
   with open("CS210_Project_Three_Input_File.txt") as input_List:       # With allows for better syntax and exception handling and automatically closes file.
        purchasedDict = Counter(line.split()[0] for line in input_List) # Counts the frequency of each string on each line of input.txt
        for groceryItem, quantity in purchasedDict.items():             # For each key and value of purchasedDict
            print('   {:<14} {:>3}'.format(groceryItem, quantity))      # Print the key and value formated.
       
def	ItemSearch(validInputString):                                       # Takes validInputString as key and returns the value
      with open("CS210_Project_Three_Input_File.txt") as input_List:
        purchasedDict = Counter(line.split()[0] for line in input_List)
        
        quantity = purchasedDict.get(validInputString)                  # Assign the value for key validInputString
        if quantity is None:                                            # If the input is not a key then
            quantity = 0                                                # Assign 0
                                                                     
        return quantity

def DisplayHistogram():                                                 # Opens Input.txt reads then writes to frequency.dat
    out_file = open("frequency.dat", mode='w')
    with open("CS210_Project_Three_Input_File.txt") as input_List:                         
        purchasedDict = Counter(line.split()[0] for line in input_List)
        for groceryItem, quantity in purchasedDict.most_common():       # For each key and value
           out_file.write('{} {}\n'.format(groceryItem, quantity))      # Format and write to frequency.dat
           
    out_file.close()

