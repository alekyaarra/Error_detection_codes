
def calculate_parity(data, parity_type='even'):
    ones_count = sum(int(bit) for bit in data)
    if parity_type == 'even':
        if ones_count % 2 == 0:
            return '0'
        else:
            return '1'
    elif parity_type == 'odd':
        if ones_count % 2 == 0:
            return '1'
        else:
            return '0'

def add_parity_bit(data, parity_type='even'):
    parity_bit = calculate_parity(data, parity_type)
    return data + parity_bit

def check_parity(data, parity_type='even'):
    received_parity_bit = data[-1]
    calculated_parity_bit = calculate_parity(data[:-1], parity_type)
    if received_parity_bit == calculated_parity_bit:
        return "Parity check passed: No error detected"
    else:
        return "Parity check failed: Error detected"

def menu():
    print("1. Even Parity")
    print("2. Odd Parity")
    print("3. Exit")

while True:
    menu()
    choice = input("Enter your choice: ")

    if choice == '1':
        binary_data = input("Enter binary codeword: ")
        codeword = add_parity_bit(binary_data, 'even')
        print("Codeword with even parity bit:", codeword)

        while True:
            received_data = input("Enter received codeword to cross-check (or type 'exit' to quit): ")
            if received_data.lower() == 'exit':
                print("Exiting...")
                break
            result = check_parity(received_data, 'even')
            print(result)

    elif choice == '2':
        binary_data = input("Enter binary codeword: ")
        codeword = add_parity_bit(binary_data, 'odd')
        print("Codeword with odd parity bit:", codeword)

        while True:
            received_data = input("Enter received codeword to cross-check (or type 'exit' to quit): ")
            if received_data.lower() == 'exit':
                print("Exiting...")
                break
            result = check_parity(received_data, 'odd')
            print(result)

    elif choice == '3':
        print("Exiting...")
        break

    else:
        print("Invalid choice. Please enter a valid option.")
