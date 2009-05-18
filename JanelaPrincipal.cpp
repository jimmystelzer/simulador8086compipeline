#include "JanelaPrincipal.h"

//(*InternalHeaders(JanelaPrincipal)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include <wx/msgdlg.h>



//(*IdInit(JanelaPrincipal)
const long JanelaPrincipal::ID_BUTTON1 = wxNewId();
const long JanelaPrincipal::ID_BUTTON2 = wxNewId();
const long JanelaPrincipal::ID_STATICLINE1 = wxNewId();
const long JanelaPrincipal::ID_STATICLINE2 = wxNewId();
const long JanelaPrincipal::ID_BUTTON3 = wxNewId();
const long JanelaPrincipal::ID_LISTCTRL2 = wxNewId();
const long JanelaPrincipal::ID_LISTCTRL1 = wxNewId();
const long JanelaPrincipal::ID_BUTTON4 = wxNewId();
const long JanelaPrincipal::ID_LISTCTRL3 = wxNewId();
const long JanelaPrincipal::ID_STATICTEXT1 = wxNewId();
const long JanelaPrincipal::ID_STATICTEXT2 = wxNewId();
const long JanelaPrincipal::ID_STATICTEXT3 = wxNewId();
const long JanelaPrincipal::ID_BUTTON5 = wxNewId();
const long JanelaPrincipal::ID_BUTTON6 = wxNewId();
const long JanelaPrincipal::ID_BUTTON7 = wxNewId();
const long JanelaPrincipal::ID_STATICLINE3 = wxNewId();
const long JanelaPrincipal::ID_BUTTON8 = wxNewId();
const long JanelaPrincipal::ID_MemView = wxNewId();
const long JanelaPrincipal::ID_STATICTEXT4 = wxNewId();
const long JanelaPrincipal::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(JanelaPrincipal,wxFrame)
	//(*EventTable(JanelaPrincipal)
	//*)
END_EVENT_TABLE()

JanelaPrincipal::JanelaPrincipal(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    this->cpu = new PipelineCPU();

    std::string titulo1("Simulador 8086 com pipeline - v.: ");
    std::string tituloversion(AutoVersion::FULLVERSION_STRING);
    std::string tituloversionstatus(AutoVersion::STATUS_SHORT);

    titulo1.append(tituloversion).append(tituloversionstatus);

	wxString titulo(titulo1.c_str(), wxConvUTF8);

	//(*Initialize(JanelaPrincipal)
	Create(parent, wxID_ANY, titulo, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(800,460));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Sobre"), wxPoint(704,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Abrir = new wxButton(Panel1, ID_BUTTON2, _("Abrir"), wxPoint(704,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(704,42), wxSize(88,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxPoint(704,82), wxSize(88,2), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	Executar = new wxButton(Panel1, ID_BUTTON3, _("Executar"), wxPoint(704,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Registradores = new wxListCtrl(Panel1, ID_LISTCTRL2, wxPoint(8,32), wxSize(680,72), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxRAISED_BORDER, wxDefaultValidator, _T("ID_LISTCTRL2"));
	Pipeline = new wxListCtrl(Panel1, ID_LISTCTRL1, wxPoint(8,224), wxSize(680,56), wxLC_REPORT|wxLC_SINGLE_SEL|wxRAISED_BORDER, wxDefaultValidator, _T("ID_LISTCTRL1"));
	Resetar = new wxButton(Panel1, ID_BUTTON4, _("Resetar"), wxPoint(704,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Flags = new wxListCtrl(Panel1, ID_LISTCTRL3, wxPoint(8,136), wxSize(680,56), wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxRAISED_BORDER, wxDefaultValidator, _T("ID_LISTCTRL3"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Registradores:"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Flags:"), wxPoint(8,112), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Pipeline:"), wxPoint(8,200), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	reg_info = new wxButton(Panel1, ID_BUTTON5, _("Informações"), wxPoint(104,0), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	flag_info = new wxButton(Panel1, ID_BUTTON6, _("Informações"), wxPoint(48,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	pipeline_info = new wxButton(Panel1, ID_BUTTON7, _("Informações"), wxPoint(64,192), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	StaticLine3 = new wxStaticLine(Panel1, ID_STATICLINE3, wxPoint(704,168), wxSize(88,0), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
	Button2 = new wxButton(Panel1, ID_BUTTON8, _("Dump"), wxPoint(704,176), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	MemView = new wxListCtrl(Panel1, ID_MemView, wxPoint(8,312), wxSize(680,128), wxLC_REPORT|wxLC_SINGLE_SEL|wxRAISED_BORDER, wxDefaultValidator, _T("ID_MemView"));
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Visualizador de Memória:"), wxPoint(8,288), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FileDialog1 = new wxFileDialog(this, _("Escolha um arquivo para abrir"), wxEmptyString, wxEmptyString, _T("NASM list files (*.lst)|*.lst|"), wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::OnAbrirClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::OnExecutarClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::OnResetarClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::Onreg_infoClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::Onflag_infoClick);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::Onpipeline_infoClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&JanelaPrincipal::OnButton2Click);
	//*)
    Reset();
}

JanelaPrincipal::~JanelaPrincipal()
{
	//(*Destroy(JanelaPrincipal)
	//*)
}


void JanelaPrincipal::OnButton1Click(wxCommandEvent& event)
{
    JanelaSobre dialog(this);
    dialog.ShowModal();
}

void JanelaPrincipal::Reset()
{
    this->cpu->reset();
    getDadosCPU();
}

void JanelaPrincipal::getDadosCPU(){
    // Registradores
    Registradores->ClearAll();
    Registradores->InsertColumn(0,_("AX"));     //Acumulator
	Registradores->InsertColumn(1,_("BX"));     //Base
	Registradores->InsertColumn(2,_("CX"));     //Count
	Registradores->InsertColumn(3,_("DX"));     //Data  (Em alguns casos os registradores DX:AX são concatenados formando um registrador de 32bits para ser usado em instruções como MUL e DIV)
	Registradores->InsertColumn(4,_("IP"));     //Instruction Pointer
	Registradores->InsertColumn(5,_("SP"));     //Stack Pointer
    Registradores->InsertColumn(6,_("BP"));     //Base Pointer
	Registradores->InsertColumn(7,_("SI"));     //Souce Index
	Registradores->InsertColumn(8,_("DI"));     //Destination Index
	Registradores->InsertColumn(9,_("CS"));     //Code Segment
	Registradores->InsertColumn(10,_("DS"));    //Data Segment
	Registradores->InsertColumn(11,_("SS"));    //Stack Segment
	Registradores->InsertColumn(12,_("ES"));    //Extra Segment
    Registradores->InsertItem(0,wxString(cpu->getAX().c_str(), wxConvUTF8));    //AX
	Registradores->SetItem(0,1,wxString(cpu->getBX().c_str(), wxConvUTF8));     //BX
    Registradores->SetItem(0,2,wxString(cpu->getCX().c_str(), wxConvUTF8));     //CX
    Registradores->SetItem(0,3,wxString(cpu->getDX().c_str(), wxConvUTF8));     //DX
    Registradores->SetItem(0,4,wxString(cpu->getIP().c_str(), wxConvUTF8));     //IP
	Registradores->SetItem(0,5,wxString(cpu->getSP().c_str(), wxConvUTF8));     //SP
    Registradores->SetItem(0,6,wxString(cpu->getBP().c_str(), wxConvUTF8));     //BP
    Registradores->SetItem(0,7,wxString(cpu->getSI().c_str(), wxConvUTF8));     //SI
    Registradores->SetItem(0,8,wxString(cpu->getDI().c_str(), wxConvUTF8));     //DI
    Registradores->SetItem(0,9,wxString(cpu->getCS().c_str(), wxConvUTF8));     //CS
	Registradores->SetItem(0,10,wxString(cpu->getDS().c_str(), wxConvUTF8));    //DS
    Registradores->SetItem(0,11,wxString(cpu->getSS().c_str(), wxConvUTF8));    //SS
    Registradores->SetItem(0,12,wxString(cpu->getES().c_str(), wxConvUTF8));    //ES

    // Flags
    Flags->ClearAll();
    Flags->InsertColumn(0,_("CF"));             //Carry
    Flags->InsertColumn(1,_("ZF"));             //Zero
    Flags->InsertColumn(2,_("SF"));             //Sign
    Flags->InsertColumn(3,_("OF"));             //Overflow
    Flags->InsertColumn(4,_("PF"));             //Parity
    Flags->InsertColumn(5,_("AF"));             //Auxiliary Carry
    Flags->InsertColumn(6,_("IF"));             //Interupt
    Flags->InsertColumn(7,_("DF"));             //Direction
    Flags->InsertItem(0,wxString(cpu->getCF().c_str(), wxConvUTF8));    //CF
    Flags->SetItem(0,1,wxString(cpu->getZF().c_str(), wxConvUTF8)); //ZF
    Flags->SetItem(0,2,wxString(cpu->getSF().c_str(), wxConvUTF8)); //SF
    Flags->SetItem(0,3,wxString(cpu->getOF().c_str(), wxConvUTF8)); //OF
    Flags->SetItem(0,4,wxString(cpu->getPF().c_str(), wxConvUTF8)); //PF
    Flags->SetItem(0,5,wxString(cpu->getAF().c_str(), wxConvUTF8)); //AF
    Flags->SetItem(0,6,wxString(cpu->getIF().c_str(), wxConvUTF8)); //IF
    Flags->SetItem(0,7,wxString(cpu->getDF().c_str(), wxConvUTF8)); //DF

    //_("Data")
    MemView->ClearAll();
    MemView->InsertColumn(0,_("Segmento"));
    MemView->SetColumnWidth(0,80);
    MemView->InsertColumn(1,_("Conteúdo"));
    MemView->SetColumnWidth(1,580);

    MemView->InsertItem(0,_("Data"));
    MemView->SetItem(0,1,wxString(cpu->getDataMem().c_str(), wxConvUTF8));
    MemView->InsertItem(1,_("Code"));
    MemView->SetItem(1,1,wxString(cpu->getCodeMem().c_str(), wxConvUTF8));

    Pipeline->ClearAll();
    Pipeline->InsertColumn(0,_("IF"));          //Instruction Fetch
    Pipeline->SetColumnWidth(0,130);
    Pipeline->InsertColumn(1,_("ID"));          //Instruction Decode
    Pipeline->SetColumnWidth(1,130);
    Pipeline->InsertColumn(2,_("EX"));          //Execute
    Pipeline->SetColumnWidth(2,130);
    Pipeline->InsertColumn(3,_("MEM"));         //Memory Access
    Pipeline->SetColumnWidth(3,130);
    Pipeline->InsertColumn(4,_("WB"));          //Register Write Back
    Pipeline->SetColumnWidth(4,130);
    Pipeline->InsertItem(0,wxString(cpu->getPIF().c_str(), wxConvUTF8));
    Pipeline->SetItem(0,1,wxString(cpu->getPID().c_str(), wxConvUTF8));
    Pipeline->SetItem(0,2,wxString(cpu->getPEX().c_str(), wxConvUTF8));
    Pipeline->SetItem(0,3,wxString(cpu->getPMEM().c_str(), wxConvUTF8));
    Pipeline->SetItem(0,4,wxString(cpu->getPWB().c_str(), wxConvUTF8));
}
void JanelaPrincipal::OnResetarClick(wxCommandEvent& event)
{
    Reset();
}

void JanelaPrincipal::OnAbrirClick(wxCommandEvent& event)
{
    std::string titulo1("Simulador 8086 com pipeline - v.: ");
    std::string tituloversion(AutoVersion::FULLVERSION_STRING);
    std::string tituloversionstatus(AutoVersion::STATUS_SHORT);

    titulo1.append(tituloversion).append(tituloversionstatus);

    wxString titulo(titulo1.c_str(), wxConvUTF8);

    // Cria um dialogo para abrir nosso objeto compilado do assemble
    if  (FileDialog1->ShowModal() == wxID_OK) { //abriu o arquivo
        Reset();

        SetTitle(titulo + FileDialog1->GetPath());
        this->cpu->readFile(std::string((FileDialog1->GetPath()).mb_str()));
        wxMessageBox(_("Arquivo carregado com êxito."),_("Abrir Arquivo."));
        getDadosCPU();
    }else{
        SetTitle(titulo);
    }
}

void JanelaPrincipal::Onflag_infoClick(wxCommandEvent& event)
{
    wxMessageBox(_("As flags são bits de um registrador de 16 bits, alguns bits são reservados e não atuam como flags.\n\nO processador 8086 usa os seguintes flags: CF - Carry Flag; ZF - Zero Flag; SF - Sing Flag; OF - Overflow Flag; PF - Parity Flag; AF - Auxiliary Flag; IF - Interrupt enable Flag e DF - Direction Flag."), _("Informações sobre flags"));
}

void JanelaPrincipal::Onpipeline_infoClick(wxCommandEvent& event)
{
    wxMessageBox(_("O pipeline arquiteturado possue cinco estágios, sendo IF (Instruction fetch), ID (Instruction decode and register fetch), EX (Execute), MEM(Memory access) e WB (Register write back)"), _("Informações sobre pipeline"));
}

void JanelaPrincipal::Onreg_infoClick(wxCommandEvent& event)
{
    wxMessageBox(_("Todos os registradores são de 16 bits, os registradores AX (acumulator), BX (base), CX (count) e DX (data) podem ser acessados por um par de registradores para área alta e baixa que são AL, AH, BL, BH, CL, CH, DL e DH.\nOs registradores DX e AX podem ser combinados em um registrador de 32 bits DX:AX para executar algumas operações (ex. multiplicação).\nOs registradores CS, DS, SS e ES atuam como ponteiros para os seguimentos da memoria.\nSP, BP, SI e DI servem como index e ponteiros de pilha em operações de acesso a memória.\nIP aponta para a proxima instrução."), _("Informações sobre registradores"));
}

void JanelaPrincipal::OnButton2Click(wxCommandEvent& event)
{
    wxMessageBox(_("Dois arquivos de nome DataMem.txt e CodeMem.txt foram gerados da diretoria de execução do simulador."), _("Dump da memória"), wxOK);
}


void JanelaPrincipal::OnExecutarClick(wxCommandEvent& event)
{
    this->cpu->exec();
    getDadosCPU();

}
