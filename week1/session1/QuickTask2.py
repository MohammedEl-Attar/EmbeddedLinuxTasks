def login_system():
    users = {
        "Ahmed": "1394",
        "Ali": "6078",
        "Amr": "9345"
    }

    username = input("User Name: ")
    password = input("Password: ")

    if username in users and password == users[username]:
        print("Welcome!")
    else:
        print("Incorrect entry.")


login_system()

