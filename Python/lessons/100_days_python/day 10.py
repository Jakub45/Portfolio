# calculator program.

def add(n1, n2):
    return n1 + n2
def substract(n1, n2):
    return n1 - n2
def multiply(n1, n2):
    return n1 * n2
def divide(n1, n2):
    return n1 / n2


if __name__ == "__main__":
    def calculator():
        try:
            operations = {
                "+": add,
                "-": substract,
                "*": multiply,
                "/": divide
            }

            first_number = float(input("Give a number: "))



            for symbol in operations:
                print(symbol)
            another_actions = True
            while another_actions :
                operation_symbol = input("Pick an operation from the line above: ")
                second_number = float(input("Give me second number: "))
                calculation_function = operations[operation_symbol]
                answer = calculation_function(first_number,second_number)

                print(f"{first_number} {operation_symbol} {second_number} = {answer}")

                if input("You want to do something else with answer ? 'yes', or 'no'") =="yes":
                    first_number = answer
                else:
                    another_actions = False
                    calculator()
        except Exception as e:
            print("Unexpected exception occured !!!: " + str(e))
            return False
        return True
    calculator()







































# def format_name(f_name,l_name):
#     # if f_name == "" or l_name == "":
#     formated_f_name = f_name.title()
#     formated_l_name = l_name.title()
#     return f"{formated_f_name} {formated_l_name}"
#
# print(format_name(
# input("what is your name ?"),
# input("What is your last name?")))


# def is_leap(year):
#     if year % 4 == 0:
#         if year % 100 == 0:
#             if year % 400 == 0:
#                 return True
#             else:
#                 return False
#         else:
#             return True
#     else:
#         return False
#
# def days_in_month(year, month):
#     month_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
#     if is_leap(year) and month == 2:
#         return 29
#     return month_days[month - 1]
# year = int(input("Enter a year: "))
# month = int(input("Enter a month: "))
# days = days_in_month(year,month)
# print(days)



