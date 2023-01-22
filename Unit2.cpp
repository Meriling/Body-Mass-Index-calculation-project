//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
float h,m,result;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if (Edit1->Text=="" ||Edit2->Text=="") {
        ShowMessage("Введите значения!");
	}
	else
	{
		h=StrToFloat(Edit1->Text)/100;
		m=StrToFloat(Edit2->Text);
		result=m/(h*h);

		if (result<16.5) {
			Label6->Caption="Выраженный дефицит массы";
			Label6->Font->Color=clGreen;
		}
		else
		if(result>=16.5 && result<=18.49){
		   Label6->Caption="Недостаточная (дефицит) масса тела";
		   Label6->Font->Color=clMaroon;
		}
		else
		if (result>=18.5 && result<=24.99) {
			Label6->Caption="Норма";
			Label6->Font->Color=clBlue;
		}
		else
		if (result>=25 && result<=29.99) {
			Label6->Caption="Избыточная масса тела (предожирение)";
			Label6->Font->Color=clPurple;
		}
		else
		if (result>=30 && result<=34.99) {
			Label6->Caption="Ожирение первой степени";
			Label6->Font->Color=clFuchsia;
		}
		else
		if (result>=35 && result<=39.99) {
			Label6->Caption="Ожирение второй степени";
			Label6->Font->Color=clOlive;
		}
		else
		if (result>=40) {
			Label6->Caption="Ожирение третьей степени (морбидное)";
			Label6->Font->Color=clRed;
		}

		Label3->Caption=FloatToStr(result);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1Change(TObject *Sender)
{
Edit1->NumbersOnly= true;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit2Change(TObject *Sender)
{
 Edit2->NumbersOnly= true;

}
//---------------------------------------------------------------------------

