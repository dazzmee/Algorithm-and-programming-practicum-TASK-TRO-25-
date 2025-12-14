# Fungsi untuk mendapatkan nilai dari pengguna
def get_grades_from_user():
    grades = []
    while True:
        try:
            grade = int(input("Masukkan nilai (0-10) atau -1 untuk berhenti: "))
            if grade == -1:
                break
            elif 0 <= grade <= 10:
                grades.append(grade)
            else:
                print("Nilai harus antara 0 dan 10!")
        except ValueError:
            print("Masukkan angka yang valid!")

    return grades


# Fungsi menghitung nilai minimum
def compute_list_minimum(number_list):
    if not number_list:
        return None
    minimum = number_list[0]
    for num in number_list:
        if num < minimum:
            minimum = num
    return minimum


# Fungsi menghitung nilai maksimum
def compute_list_maximum(number_list):
    if not number_list:
        return None
    maximum = number_list[0]
    for num in number_list:
        if num > maximum:
            maximum = num
    return maximum


# Fungsi menghitung rata-rata
def compute_list_average(number_list):
    if not number_list:
        return None
    total = 0
    for num in number_list:
        total += num
    average = total / len(number_list)
    return average

print("=== Program Penghitung Nilai (Min, Max, Average) ===")
grades = get_grades_from_user()

if len(grades) == 0:
    print("Kamu belum memasukkan nilai apapun.")
else:
    print(f"\nKamu telah memasukkan {len(grades)} nilai: {grades}")
    minimum = compute_list_minimum(grades)
    maximum = compute_list_maximum(grades)
    average = compute_list_average(grades)

    print(f"Nilai Minimum : {minimum}")
    print(f"Nilai Maksimum: {maximum}")
    print(f"Nilai Rata-rata: {average:.2f}")
