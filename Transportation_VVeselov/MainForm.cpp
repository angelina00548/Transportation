#include "MainForm.h"
#include <string>

using namespace System;
using namespace System ::Windows::Forms;

[STAThreadAttribute]


void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Transportation::MainForm form;
	Application::Run(% form);
}


System::Void Transportation::MainForm::startButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	fDialog->FileName = fNameBox->Text;

	if (IO::File::Exists(fNameBox->Text)) {
		if (IO::Path::GetExtension(fDialog->FileName) == ".xls" || IO::Path::GetExtension(fDialog->FileName) == ".xlsx")
			MessageBox::Show("��� � �������!", "�����������");
			//���������� � ��������� ������ ��������
		else
			MessageBox::Show("�������� ������ �����!\n���������� ����� ������ ���� xls ��� xlsx", "������!");
	}
	else
		MessageBox::Show("���� �� ������!", "������!");

	return System::Void();
}


System::Void Transportation::MainForm::fSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	fDialog->Filter = "*.xls;*.xlsx|*.xls;*.xlsx";

	if (fDialog->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		return;

	String^ filename = fDialog->FileName;

	fNameBox->Text = fDialog->FileName;
	MessageBox::Show("���� ��������!", "�����������");

	return System::Void();
}
