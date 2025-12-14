# Fungsi untuk menampilkan petunjuk
def print_instructions():
    print("Welcome to the calculator!")
    print("Provide 2 numbers and then choose the operation type:")
    print("1 = Addition (+)")
    print("2 = Subtraction (-)")
    print("3 = Multiplication (×)")
    print("4 = Division (÷)")
    print("-" * 40)


# Fungsi operasi dasar
def add_2_numbers(number_1, number_2):
    return number_1 + number_2

def subtract_2_numbers(number_1, number_2):
    return number_1 - number_2

def multiply_2_numbers(number_1, number_2):
    return number_1 * number_2

def divide_2_numbers(number_1, number_2):
    return number_1 / number_2

print_instructions()

try:
    number_1 = float(input("Masukkan angka pertama: "))
    number_2 = float(input("Masukkan angka kedua: "))
    operation = int(input("Pilih operasi (1=+, 2=-, 3=×, 4=÷): "))

    # Kondisi operasi
    if operation == 1:
        result = add_2_numbers(number_1, number_2)
        print(f"Hasil penjumlahan: {result}")

    elif operation == 2:
        result = subtract_2_numbers(number_1, number_2)
        print(f"Hasil pengurangan: {result}")

    elif operation == 3:
        result = multiply_2_numbers(number_1, number_2)
        print(f"Hasil perkalian: {result}")

    elif operation == 4:
        if number_2 != 0:
            result = divide_2_numbers(number_1, number_2)
            print(f"Hasil pembagian: {result}")
        else:
            print("⚠️ Error: Tidak bisa dibagi dengan nol!")

    else:
        print("⚠️ Nomor operasi tidak valid! Gunakan 1, 2, 3, atau 4.")

except ValueError:
    print("❌ Input tidak valid! Masukkan angka yang benar.")
