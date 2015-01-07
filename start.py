import sys
from PyQt5 import QtCore, QtGui,QtWidgets

from main_window_ui import Ui_MainWindow


class MyForm(QtWidgets.QMainWindow):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.ui.test_btn.clicked.connect(self.btn_clicked)
    def btn_clicked(self):
        QtWidgets.QMessageBox.critical(self,"dshfs","fadsfasd")



if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    myapp = MyForm()
    myapp.show()
    sys.exit(app.exec_())
