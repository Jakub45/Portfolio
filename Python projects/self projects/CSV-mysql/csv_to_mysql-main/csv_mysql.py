import mysql.connector
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import sys
import pandas as pd
import configparser
import os


global db_connected
db_connected = False
global csv_loaded
csv_loaded = False
global csv_data
csv_data = None
global db_cursor
db_cursor = None
CONFIG_FILE = 'config.ini'

global HOST
global USER
global PASSWORD
global DATABASE


class DatabaseApp(QMainWindow):
    def __init__(self):
        super().__init__()

        # Load configuration
        self.config_file = "config.ini"
        self.load_config()

        # Set up the window
        self.setWindowTitle(self.config.get("Application", "window_title", fallback="CSV to MySQL Importer"))
        self.setGeometry(100, 100, 1200, 600)  # Adjusted height to fit config editor

        # Main layout
        main_layout = QVBoxLayout()

        # Top layout (buttons on the left, table selector and table on the right)
        top_layout = QHBoxLayout()

        # Left-side layout with buttons
        left_layout = QVBoxLayout()

        # Buttons
        self.select_csv_button = QPushButton("Select CSV File")
        self.load_data_button = QPushButton("Load Data to Database")
        self.edit_config_button = QPushButton("Edit Config File")  # Button to edit config file
        self.custom_action_button = QPushButton("Connect to the Database")  # New button with empty action

        # Button styles
        button_style = """
            QPushButton {
                font-size: 16px;
                padding: 10px;
                min-width: 200px;
                min-height: 50px;
            }
        """
        self.select_csv_button.setStyleSheet(button_style)
        self.load_data_button.setStyleSheet(button_style)
        self.edit_config_button.setStyleSheet(button_style)
        self.custom_action_button.setStyleSheet(button_style)

        # Add buttons to left-side layout
        left_layout.addWidget(self.select_csv_button)
        left_layout.addWidget(self.load_data_button)
        left_layout.addWidget(self.edit_config_button)
        left_layout.addWidget(self.custom_action_button)

        # Right-side layout for dropdown and table
        right_layout = QVBoxLayout()

        # Dropdown for table selection, placed above the table
        self.table_selector = QComboBox()
        self.table_selector.addItems([self.config.get("Application", "default_table", fallback="produkcja"), "zlecenia"])
        self.table_selector.currentTextChanged.connect(self.update_table_view)
        right_layout.addWidget(self.table_selector)

        # Table widget to display database contents
        self.table_widget = QTableWidget()
        right_layout.addWidget(self.table_widget)

        # Add left and right layouts to the top layout
        top_layout.addLayout(left_layout)
        top_layout.addLayout(right_layout)

        # Add top layout to the main layout
        main_layout.addLayout(top_layout)

        # Text field to display raw CSV content
        self.csv_text_display = QTextEdit()
        self.csv_text_display.setReadOnly(True)  # Make it read-only to prevent editing
        main_layout.addWidget(self.csv_text_display)

        # Text editor for config file
        self.config_text_display = QTextEdit()
        main_layout.addWidget(self.config_text_display)
        self.config_text_display.hide()  # Hide the config editor initially

        # Save Config button
        self.save_config_button = QPushButton("Save Config Changes")
        self.save_config_button.clicked.connect(self.save_config)
        main_layout.addWidget(self.save_config_button)
        self.save_config_button.hide()  # Hide the save button initially

        # Central widget
        container = QWidget()
        container.setLayout(main_layout)
        self.setCentralWidget(container)

        # Connect signals to slots
        self.select_csv_button.clicked.connect(self.select_csv_file)
        self.load_data_button.clicked.connect(self.load_data_to_database)
        self.edit_config_button.clicked.connect(self.edit_config)
        self.custom_action_button.clicked.connect(self.connect_to_database)  # Connect to empty method


    def load_config(self):
        """Load the configuration file."""
        self.config = configparser.ConfigParser()
        self.config.read(self.config_file)

    def edit_config(self):
        """Open and display the config file in the text editor."""
        with open(self.config_file, 'r') as file:
            config_content = file.read()
            self.config_text_display.setPlainText(config_content)  # Display the config content in the text editor
            self.config_text_display.show()  # Show the text editor
            self.save_config_button.show()   # Show the save button

    def save_config(self):
        """Save changes to the config file."""
        with open(self.config_file, 'w') as file:
            file.write(self.config_text_display.toPlainText())  # Save the updated config content
        self.load_config()  # Reload the updated config
        QMessageBox.information(self, "Config Saved", "Changes to the config file have been saved.")
        self.config_text_display.hide()
        self.save_config_button.hide()

    def select_csv_file(self):
        global csv_data
        global csv_loaded
        options = QFileDialog.Options()
        file_path, _ = QFileDialog.getOpenFileName(self, "Open CSV File", "", "CSV Files (*.csv);;All Files (*)", options=options)
        csv_loaded = True
        if file_path:
            # Display raw CSV content in the text field
            with open(file_path, 'r') as file:
                csv_content = file.read()
                self.csv_text_display.setPlainText("Loaded CSV file: \r\n" + csv_content)  # Display raw text in the text field
            csv_data = pd.read_csv(file_path, header=None)
            QMessageBox.information(self, "CSV Loaded", f"Loaded {len(csv_data)} rows from {file_path}")

    def load_data_to_database(self):
        global db_connected
        global csv_loaded
        global csv_data
        global db_cursor
        if csv_loaded is False:
            QMessageBox.warning(self, "No CSV", "Please select a CSV file first.")
            return
        if db_connected is False:
            QMessageBox.warning(self, "No Database Connection", "Please connect to the database first.")
            return

        first_row = csv_data.iloc[0, 0]  # Access the first row, first column
        fields = first_row.split(";")  # Split by semicolon
        seria = fields[1]

        zlecenia_query = f"INSERT INTO `" + str(DATABASE) + "`.`zlecenia` (`seria`, `stan`) VALUES ('" + str(seria) + "', '0');"
        try:
            db_cursor.execute(zlecenia_query)
            db_connection.commit()
            zlecID = db_cursor.lastrowid
            try:

                for index, row in csv_data.iterrows():
                    fields = (row.values[0].split(";"))
                    seria = fields[1]
                    ref = fields[2]
                    typ = fields[3]
                    rh = int(str(fields[4]).replace(".", ""))
                    szt = fields[4]
                    wyk = 0
                    stan = 0
                    insert_query = f"INSERT INTO `" + str(DATABASE) + "`.`produkcja` (`seria`, `ref`, `typ`, `rh`, `szt`, `wyk`, `stan`, `zlecID`) VALUES ('" + str(
                        seria) + "', '" + str(ref) + "', '" + str(typ) + "', '" + str(rh) + "', '" + str(
                        szt) + "', '" + str(wyk) + "', '" + str(stan) + "', '" + str(zlecID) + "');"
                    self.csv_text_display.setPlainText("Executing SQL query: " + insert_query)  # Display raw text in the text field
                    db_cursor.execute(insert_query)
                    db_connection.commit()
                QMessageBox.information(self, "Data Loaded", "CSV data has been successfully loaded into the database.")
                self.update_table_view()
            except Exception as e:
                QMessageBox.critical(self, "Error", f"Failed to insert data into produkcja table: {e}")
        except Exception as e:
            QMessageBox.critical(self, "Error", f"Failed to insert data into zlecenia table: {e}")

    def update_table_view(self):
        global db_cursor
        global db_connected
        selected_table = self.table_selector.currentText()

        # Retrieve data from the selected table
        query = f"SELECT * FROM {selected_table}"

        if db_connected == True:
            try:
                db_cursor.execute(query)
                rows = db_cursor.fetchall()
                columns = [i[0] for i in db_cursor.description]

                # Set up the table widget
                self.table_widget.clear()
                self.table_widget.setRowCount(len(rows))
                self.table_widget.setColumnCount(len(columns))
                self.table_widget.setHorizontalHeaderLabels(columns)

                # Populate the table widget with data
                for row_idx, row_data in enumerate(rows):
                    for col_idx, value in enumerate(row_data):
                        self.table_widget.setItem(row_idx, col_idx, QTableWidgetItem(str(value)))
            except Exception as e:
                QMessageBox.critical(self, "Error", f"Failed to refresh the table: {e}")
        else:
            QMessageBox.critical(self, "Error","Please connect to the database first.")

    def connect_to_database(self):
        # Specify that we are using global variables
        global db_connection
        global db_cursor
        global db_connected
        global HOST
        global USER
        global PASSWORD
        global DATABASE
        try:
            # Initialize the ConfigParser
            config = configparser.ConfigParser()

            # Read the config file
            config.read(CONFIG_FILE)

            # Accessing config values
            HOST = config.get("Database", "host")
            USER = config.get("Database", "user")
            PASSWORD = config.get("Database", "password")
            DATABASE = config.get("Database", "database")
        except Exception as e:
            return_message = "Unable to properly read config file, error message: " + str(e)
            QMessageBox.information(self, "Config file parsing error", return_message)

        try:
            db_connection = mysql.connector.connect(
                host=HOST,
                user=USER,
                password=PASSWORD,
                database=DATABASE
            )
            db_cursor = db_connection.cursor()
            db_connected = True

            return_message = "Connection successful!"
            QMessageBox.information(self, "Database connection", return_message)
            # Initialize the table view
            self.update_table_view()

        except Exception as e:
            return_message = "Unable to connect to the database, error message: " + str(e)
            QMessageBox.information(self, "Database connection error", return_message)
            db_connected = False



if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = DatabaseApp()
    window.show()
    sys.exit(app.exec_())
