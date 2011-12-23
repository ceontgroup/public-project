#pragma once
#include "DiskInfo.h"
#include "Windows.h"
namespace Gui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;	

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			extern DiskInfo diskInfo;
			for (int drive = 0; drive < diskInfo.getHDisks().size(); drive ++){
				char driveName [256];
				sprintf_s(driveName, "PhysicalDrive%d", drive);
				String^ c = gcnew String(driveName);
				cbHDisk->Items->Add(c);
			}						
			for (int i = 0; i < diskInfo.getPartitions().size(); i ++){				
				String^ c = gcnew String(diskInfo.getPartitions()[i]->rootPathName.data());
				cbPartiton->Items->Add(c);
			}						
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TabControl^  tabControl;
	private: System::Windows::Forms::TabPage^  tabHDiskPage;
	private: System::Windows::Forms::TabPage^  tabPartitionPage;
	private: System::Windows::Forms::TabPage^  tabInformation;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  txtType;
	private: System::Windows::Forms::TextBox^  txtFileSystem;
	private: System::Windows::Forms::TextBox^  txtRootPath;
	private: System::Windows::Forms::TextBox^  txtSize;

	private: System::Windows::Forms::TextBox^  txtFreeSize;
	private: System::Windows::Forms::TextBox^  txtUsedSize;
	private: System::Windows::Forms::TextBox^  txtTotalCluster;

	private: System::Windows::Forms::TextBox^  txtSectorPerCluster;
private: System::Windows::Forms::TextBox^  txtVolumeName;


	private: System::Windows::Forms::ComboBox^  cbPartiton;

	private: System::Windows::Forms::Label^  label20;

private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::TextBox^  txtDiskType;
private: System::Windows::Forms::TextBox^  txtSerialNumber;
private: System::Windows::Forms::TextBox^  txtProductId;
private: System::Windows::Forms::TextBox^  txtDiskSize;
private: System::Windows::Forms::TextBox^  txtCylinders;
private: System::Windows::Forms::TextBox^  txtTrackPerCylinder;
private: System::Windows::Forms::TextBox^  txtSectorPerTrack;
private: System::Windows::Forms::TextBox^  txtBytePerSector;
private: System::Windows::Forms::TextBox^  txtVendorId;
private: System::Windows::Forms::ComboBox^  cbHDisk;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label21;

private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Label^  label32;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabHDiskPage = (gcnew System::Windows::Forms::TabPage());
			this->tabPartitionPage = (gcnew System::Windows::Forms::TabPage());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->txtType = (gcnew System::Windows::Forms::TextBox());
			this->txtFileSystem = (gcnew System::Windows::Forms::TextBox());
			this->txtRootPath = (gcnew System::Windows::Forms::TextBox());
			this->txtSize = (gcnew System::Windows::Forms::TextBox());
			this->txtFreeSize = (gcnew System::Windows::Forms::TextBox());
			this->txtUsedSize = (gcnew System::Windows::Forms::TextBox());
			this->txtTotalCluster = (gcnew System::Windows::Forms::TextBox());
			this->txtSectorPerCluster = (gcnew System::Windows::Forms::TextBox());
			this->txtVolumeName = (gcnew System::Windows::Forms::TextBox());
			this->cbPartiton = (gcnew System::Windows::Forms::ComboBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tabInformation = (gcnew System::Windows::Forms::TabPage());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtDiskType = (gcnew System::Windows::Forms::TextBox());
			this->txtSerialNumber = (gcnew System::Windows::Forms::TextBox());
			this->txtProductId = (gcnew System::Windows::Forms::TextBox());
			this->txtDiskSize = (gcnew System::Windows::Forms::TextBox());
			this->txtCylinders = (gcnew System::Windows::Forms::TextBox());
			this->txtTrackPerCylinder = (gcnew System::Windows::Forms::TextBox());
			this->txtSectorPerTrack = (gcnew System::Windows::Forms::TextBox());
			this->txtBytePerSector = (gcnew System::Windows::Forms::TextBox());
			this->txtVendorId = (gcnew System::Windows::Forms::TextBox());
			this->cbHDisk = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->tabControl->SuspendLayout();
			this->tabHDiskPage->SuspendLayout();
			this->tabPartitionPage->SuspendLayout();
			this->tabInformation->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tabControl, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(692, 338);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabHDiskPage);
			this->tabControl->Controls->Add(this->tabPartitionPage);
			this->tabControl->Controls->Add(this->tabInformation);
			this->tabControl->Location = System::Drawing::Point(3, 3);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(686, 332);
			this->tabControl->TabIndex = 2;
			// 
			// tabHDiskPage
			// 
			this->tabHDiskPage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tabHDiskPage.BackgroundImage")));
			this->tabHDiskPage->Controls->Add(this->pictureBox1);
			this->tabHDiskPage->Controls->Add(this->label31);
			this->tabHDiskPage->Controls->Add(this->label30);
			this->tabHDiskPage->Controls->Add(this->label29);
			this->tabHDiskPage->Controls->Add(this->label28);
			this->tabHDiskPage->Controls->Add(this->label27);
			this->tabHDiskPage->Controls->Add(this->label26);
			this->tabHDiskPage->Controls->Add(this->label25);
			this->tabHDiskPage->Controls->Add(this->label24);
			this->tabHDiskPage->Controls->Add(this->label21);
			this->tabHDiskPage->Controls->Add(this->label32);
			this->tabHDiskPage->Controls->Add(this->label23);
			this->tabHDiskPage->Location = System::Drawing::Point(4, 22);
			this->tabHDiskPage->Name = L"tabHDiskPage";
			this->tabHDiskPage->Padding = System::Windows::Forms::Padding(3);
			this->tabHDiskPage->Size = System::Drawing::Size(678, 306);
			this->tabHDiskPage->TabIndex = 0;
			this->tabHDiskPage->Text = L"Thông tin chung";
			this->tabHDiskPage->UseVisualStyleBackColor = true;
			this->tabHDiskPage->Click += gcnew System::EventHandler(this, &Form1::tabHDiskPage_Click);
			// 
			// tabPartitionPage
			// 
			this->tabPartitionPage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tabPartitionPage.BackgroundImage")));
			this->tabPartitionPage->Controls->Add(this->label11);
			this->tabPartitionPage->Controls->Add(this->label12);
			this->tabPartitionPage->Controls->Add(this->label13);
			this->tabPartitionPage->Controls->Add(this->label14);
			this->tabPartitionPage->Controls->Add(this->label15);
			this->tabPartitionPage->Controls->Add(this->label16);
			this->tabPartitionPage->Controls->Add(this->label17);
			this->tabPartitionPage->Controls->Add(this->label18);
			this->tabPartitionPage->Controls->Add(this->label19);
			this->tabPartitionPage->Controls->Add(this->txtType);
			this->tabPartitionPage->Controls->Add(this->txtFileSystem);
			this->tabPartitionPage->Controls->Add(this->txtRootPath);
			this->tabPartitionPage->Controls->Add(this->txtSize);
			this->tabPartitionPage->Controls->Add(this->txtFreeSize);
			this->tabPartitionPage->Controls->Add(this->txtUsedSize);
			this->tabPartitionPage->Controls->Add(this->txtTotalCluster);
			this->tabPartitionPage->Controls->Add(this->txtSectorPerCluster);
			this->tabPartitionPage->Controls->Add(this->txtVolumeName);
			this->tabPartitionPage->Controls->Add(this->cbPartiton);
			this->tabPartitionPage->Controls->Add(this->label20);
			this->tabPartitionPage->Location = System::Drawing::Point(4, 22);
			this->tabPartitionPage->Name = L"tabPartitionPage";
			this->tabPartitionPage->Padding = System::Windows::Forms::Padding(3);
			this->tabPartitionPage->Size = System::Drawing::Size(678, 306);
			this->tabPartitionPage->TabIndex = 1;
			this->tabPartitionPage->Text = L"Thông tin các phân vùng";
			this->tabPartitionPage->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(36, 215);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(30, 13);
			this->label11->TabIndex = 17;
			this->label11->Text = L"Loại ";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(344, 216);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(110, 13);
			this->label12->TabIndex = 18;
			this->label12->Text = L"Dung lượng còn trống";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(344, 252);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(88, 13);
			this->label13->TabIndex = 15;
			this->label13->Text = L"Tổng dung lượng";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(344, 181);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(105, 13);
			this->label14->TabIndex = 16;
			this->label14->Text = L"Dung lượng đã dùng";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(344, 142);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(80, 13);
			this->label15->TabIndex = 19;
			this->label15->Text = L"Tổng số cluster";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(344, 105);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(126, 13);
			this->label16->TabIndex = 22;
			this->label16->Text = L"Số sector trên mỗi cluster";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(36, 179);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(56, 13);
			this->label17->TabIndex = 23;
			this->label17->Text = L"Định dạng";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(36, 144);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(70, 13);
			this->label18->TabIndex = 20;
			this->label18->Text = L"Thư mục gốc";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(37, 105);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(53, 13);
			this->label19->TabIndex = 21;
			this->label19->Text = L"Tên nhãn";
			// 
			// txtType
			// 
			this->txtType->Location = System::Drawing::Point(146, 212);
			this->txtType->Name = L"txtType";
			this->txtType->ReadOnly = true;
			this->txtType->Size = System::Drawing::Size(180, 20);
			this->txtType->TabIndex = 14;
			// 
			// txtFileSystem
			// 
			this->txtFileSystem->Location = System::Drawing::Point(146, 176);
			this->txtFileSystem->Name = L"txtFileSystem";
			this->txtFileSystem->ReadOnly = true;
			this->txtFileSystem->Size = System::Drawing::Size(180, 20);
			this->txtFileSystem->TabIndex = 8;
			// 
			// txtRootPath
			// 
			this->txtRootPath->Location = System::Drawing::Point(146, 139);
			this->txtRootPath->Name = L"txtRootPath";
			this->txtRootPath->ReadOnly = true;
			this->txtRootPath->Size = System::Drawing::Size(180, 20);
			this->txtRootPath->TabIndex = 9;
			// 
			// txtSize
			// 
			this->txtSize->Location = System::Drawing::Point(478, 249);
			this->txtSize->Name = L"txtSize";
			this->txtSize->ReadOnly = true;
			this->txtSize->Size = System::Drawing::Size(154, 20);
			this->txtSize->TabIndex = 6;
			// 
			// txtFreeSize
			// 
			this->txtFreeSize->Location = System::Drawing::Point(478, 212);
			this->txtFreeSize->Name = L"txtFreeSize";
			this->txtFreeSize->ReadOnly = true;
			this->txtFreeSize->Size = System::Drawing::Size(154, 20);
			this->txtFreeSize->TabIndex = 7;
			// 
			// txtUsedSize
			// 
			this->txtUsedSize->Location = System::Drawing::Point(478, 176);
			this->txtUsedSize->Name = L"txtUsedSize";
			this->txtUsedSize->ReadOnly = true;
			this->txtUsedSize->Size = System::Drawing::Size(154, 20);
			this->txtUsedSize->TabIndex = 12;
			// 
			// txtTotalCluster
			// 
			this->txtTotalCluster->Location = System::Drawing::Point(478, 139);
			this->txtTotalCluster->Name = L"txtTotalCluster";
			this->txtTotalCluster->ReadOnly = true;
			this->txtTotalCluster->Size = System::Drawing::Size(154, 20);
			this->txtTotalCluster->TabIndex = 13;
			// 
			// txtSectorPerCluster
			// 
			this->txtSectorPerCluster->Location = System::Drawing::Point(478, 98);
			this->txtSectorPerCluster->Name = L"txtSectorPerCluster";
			this->txtSectorPerCluster->ReadOnly = true;
			this->txtSectorPerCluster->Size = System::Drawing::Size(154, 20);
			this->txtSectorPerCluster->TabIndex = 10;
			// 
			// txtVolumeName
			// 
			this->txtVolumeName->Location = System::Drawing::Point(146, 98);
			this->txtVolumeName->Name = L"txtVolumeName";
			this->txtVolumeName->ReadOnly = true;
			this->txtVolumeName->Size = System::Drawing::Size(180, 20);
			this->txtVolumeName->TabIndex = 11;
			// 
			// cbPartiton
			// 
			this->cbPartiton->FormattingEnabled = true;
			this->cbPartiton->Location = System::Drawing::Point(299, 24);
			this->cbPartiton->Name = L"cbPartiton";
			this->cbPartiton->Size = System::Drawing::Size(121, 21);
			this->cbPartiton->TabIndex = 5;
			this->cbPartiton->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbPartiton_SelectedIndexChanged);
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(206, 27);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(52, 13);
			this->label20->TabIndex = 4;
			this->label20->Text = L"Lựa chọn";
			// 
			// tabInformation
			// 
			this->tabInformation->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tabInformation.BackgroundImage")));
			this->tabInformation->Controls->Add(this->label10);
			this->tabInformation->Controls->Add(this->label9);
			this->tabInformation->Controls->Add(this->label8);
			this->tabInformation->Controls->Add(this->label7);
			this->tabInformation->Controls->Add(this->label6);
			this->tabInformation->Controls->Add(this->label5);
			this->tabInformation->Controls->Add(this->label4);
			this->tabInformation->Controls->Add(this->label3);
			this->tabInformation->Controls->Add(this->label2);
			this->tabInformation->Controls->Add(this->txtDiskType);
			this->tabInformation->Controls->Add(this->txtSerialNumber);
			this->tabInformation->Controls->Add(this->txtProductId);
			this->tabInformation->Controls->Add(this->txtDiskSize);
			this->tabInformation->Controls->Add(this->txtCylinders);
			this->tabInformation->Controls->Add(this->txtTrackPerCylinder);
			this->tabInformation->Controls->Add(this->txtSectorPerTrack);
			this->tabInformation->Controls->Add(this->txtBytePerSector);
			this->tabInformation->Controls->Add(this->txtVendorId);
			this->tabInformation->Controls->Add(this->cbHDisk);
			this->tabInformation->Controls->Add(this->label1);
			this->tabInformation->Location = System::Drawing::Point(4, 22);
			this->tabInformation->Name = L"tabInformation";
			this->tabInformation->Padding = System::Windows::Forms::Padding(3);
			this->tabInformation->Size = System::Drawing::Size(678, 306);
			this->tabInformation->TabIndex = 2;
			this->tabInformation->Text = L"Thông tin ổ cứng";
			this->tabInformation->UseVisualStyleBackColor = true;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(41, 220);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Loại đĩa";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(349, 221);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(85, 13);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Tổng số cylinder";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(349, 257);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(60, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Kích thước";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(349, 186);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(126, 13);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Số track trên mỗi cylinder";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(349, 147);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Số sector trên mỗi track";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(349, 110);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(115, 13);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Số byte trên mỗi sector";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(41, 184);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Serial";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(41, 149);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 13);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Mã sản phẩm";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Tên nhà sản xuất";
			// 
			// txtDiskType
			// 
			this->txtDiskType->Location = System::Drawing::Point(152, 217);
			this->txtDiskType->Name = L"txtDiskType";
			this->txtDiskType->ReadOnly = true;
			this->txtDiskType->Size = System::Drawing::Size(180, 20);
			this->txtDiskType->TabIndex = 14;
			// 
			// txtSerialNumber
			// 
			this->txtSerialNumber->Location = System::Drawing::Point(152, 181);
			this->txtSerialNumber->Name = L"txtSerialNumber";
			this->txtSerialNumber->ReadOnly = true;
			this->txtSerialNumber->Size = System::Drawing::Size(180, 20);
			this->txtSerialNumber->TabIndex = 8;
			// 
			// txtProductId
			// 
			this->txtProductId->Location = System::Drawing::Point(152, 144);
			this->txtProductId->Name = L"txtProductId";
			this->txtProductId->ReadOnly = true;
			this->txtProductId->Size = System::Drawing::Size(180, 20);
			this->txtProductId->TabIndex = 9;
			// 
			// txtDiskSize
			// 
			this->txtDiskSize->Location = System::Drawing::Point(483, 254);
			this->txtDiskSize->Name = L"txtDiskSize";
			this->txtDiskSize->ReadOnly = true;
			this->txtDiskSize->Size = System::Drawing::Size(154, 20);
			this->txtDiskSize->TabIndex = 6;
			// 
			// txtCylinders
			// 
			this->txtCylinders->Location = System::Drawing::Point(483, 217);
			this->txtCylinders->Name = L"txtCylinders";
			this->txtCylinders->ReadOnly = true;
			this->txtCylinders->Size = System::Drawing::Size(154, 20);
			this->txtCylinders->TabIndex = 7;
			// 
			// txtTrackPerCylinder
			// 
			this->txtTrackPerCylinder->Location = System::Drawing::Point(483, 181);
			this->txtTrackPerCylinder->Name = L"txtTrackPerCylinder";
			this->txtTrackPerCylinder->ReadOnly = true;
			this->txtTrackPerCylinder->Size = System::Drawing::Size(154, 20);
			this->txtTrackPerCylinder->TabIndex = 12;
			// 
			// txtSectorPerTrack
			// 
			this->txtSectorPerTrack->Location = System::Drawing::Point(483, 144);
			this->txtSectorPerTrack->Name = L"txtSectorPerTrack";
			this->txtSectorPerTrack->ReadOnly = true;
			this->txtSectorPerTrack->Size = System::Drawing::Size(154, 20);
			this->txtSectorPerTrack->TabIndex = 13;
			// 
			// txtBytePerSector
			// 
			this->txtBytePerSector->Location = System::Drawing::Point(483, 103);
			this->txtBytePerSector->Name = L"txtBytePerSector";
			this->txtBytePerSector->ReadOnly = true;
			this->txtBytePerSector->Size = System::Drawing::Size(154, 20);
			this->txtBytePerSector->TabIndex = 10;
			// 
			// txtVendorId
			// 
			this->txtVendorId->Location = System::Drawing::Point(152, 103);
			this->txtVendorId->Name = L"txtVendorId";
			this->txtVendorId->ReadOnly = true;
			this->txtVendorId->Size = System::Drawing::Size(180, 20);
			this->txtVendorId->TabIndex = 11;
			// 
			// cbHDisk
			// 
			this->cbHDisk->FormattingEnabled = true;
			this->cbHDisk->Location = System::Drawing::Point(304, 33);
			this->cbHDisk->Name = L"cbHDisk";
			this->cbHDisk->Size = System::Drawing::Size(121, 21);
			this->cbHDisk->TabIndex = 5;
			this->cbHDisk->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::cbHDisk_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(211, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Lựa chọn";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Red;
			this->label21->Location = System::Drawing::Point(146, 5);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(366, 18);
			this->label21->TabIndex = 6;
			this->label21->Text = L"Trường Đại Học Bách Khoa - Đại Học Đà  Nẵng";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::Red;
			this->label23->Location = System::Drawing::Point(209, 30);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(216, 18);
			this->label23->TabIndex = 4;
			this->label23->Text = L"Khoa Công Nghệ Thông Tin";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::Green;
			this->label24->Location = System::Drawing::Point(157, 123);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(350, 24);
			this->label24->TabIndex = 7;
			this->label24->Text = L"ĐỒ ÁN NGUYÊN LÝ HỆ ĐIỀU HÀNH";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(31, 161);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(52, 16);
			this->label25->TabIndex = 8;
			this->label25->Text = L"Đề tài:";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(75, 180);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(539, 16);
			this->label26->TabIndex = 8;
			this->label26->Text = L"Xây dựng chương trình hiển thị ổ đĩa, tên ổ đĩa, số serial, trạng thái, định dạng" 
				L"";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(78, 208);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(540, 16);
			this->label27->TabIndex = 9;
			this->label27->Text = L"dung lượng, dung lượng còn trống, số byte trên sector, số sector trên cluster ..." 
				L"";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(391, 236);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(226, 15);
			this->label28->TabIndex = 10;
			this->label28->Text = L"Giáo viên hướng dẫn: Trần Hồ Thủy Tiên";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(394, 253);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(95, 15);
			this->label29->TabIndex = 11;
			this->label29->Text = L"Nhóm sinh viên:";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(497, 264);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(108, 15);
			this->label30->TabIndex = 12;
			this->label30->Text = L"Lê Sữa - Lớp 08T1";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(497, 286);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(154, 15);
			this->label31->TabIndex = 12;
			this->label31->Text = L"Trịnh Duy Nhân - Lớp 08T1";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label32->ForeColor = System::Drawing::Color::Green;
			this->label32->Location = System::Drawing::Point(288, 144);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(64, 18);
			this->label32->TabIndex = 5;
			this->label32->Text = L"---*-*---";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(298, 51);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(35, 35);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 339);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Đồ án nguyên lý hệ điều hành";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tabControl->ResumeLayout(false);
			this->tabHDiskPage->ResumeLayout(false);
			this->tabHDiskPage->PerformLayout();
			this->tabPartitionPage->ResumeLayout(false);
			this->tabPartitionPage->PerformLayout();
			this->tabInformation->ResumeLayout(false);
			this->tabInformation->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion	
	private: System::Void tabHDiskPage_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void MarshalString ( String ^ s, string& os ) {
				 using namespace Runtime::InteropServices;
				 const char* chars = 
					 (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();					  
				 os = chars;
				 Marshal::FreeHGlobal(IntPtr((void*)chars));
			 }
	
	
private: System::Void cbPartiton_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 int index = cbPartiton->SelectedIndex;
			 extern DiskInfo diskInfo;
			 if (index < 0 || index > diskInfo.getPartitions().size()-1)
				 return;
			 
			 LogicalPartitionInfo *partition = diskInfo.getPartitions()[index];
			 txtVolumeName->Text = "";
			 txtVolumeName->Text = gcnew String(partition->volumeName.c_str());
			 txtRootPath->Text = "";
			 txtRootPath->Text = gcnew String(partition->rootPathName.c_str());
			 txtFileSystem->Text = "";
			 txtFileSystem->Text = gcnew String(partition->fileSystemName.c_str());
			 txtSectorPerCluster->Text = "";
			 txtSectorPerCluster->Text = Convert::ToString((long long)partition->sectorsPerCluster);
			 txtType->Text = "";
			 switch (partition->type)
			 {
			 case DRIVE_NO_ROOT_DIR:
				 txtType->Text = "DRIVE_NO_ROOT_DIR";
				 break;
			 case DRIVE_CDROM:
				 txtType->Text = "DRIVE_CDROM";
				 break;
			 case DRIVE_FIXED:
				 txtType->Text = "DRIVE_FIXED";
				 break;
			 case DRIVE_RAMDISK:
				 txtType->Text = "DRIVE_RAMDISK";
				 break;
			 case DRIVE_REMOTE:
				 txtType->Text = "DRIVE_REMOTE";
				 break;
			 case DRIVE_REMOVABLE:
				 txtType->Text = "DRIVE_REMOVABLE";
				 break;
			 case DRIVE_UNKNOWN:
				 txtType->Text = "DRIVE_UNKNOWN";
				 break;
			 } 
			 
             int size = partition->size / 1024 / 1024;
             if (size < 1024){
			    txtSize->Text = "";
                txtSize->Text = Convert::ToString((long long) partition->size / 1024 / 1024) + " MB";			 			    
             }            
             else{
                 txtSize->Text = "";
                 txtSize->Text = Convert::ToString((long long) partition->size / 1024 / 1024 / 1024) + " GB";			 			    
             }
             float c = (float) partition->numberOfFreeClusters / partition->totalNumberOfClusters;
             size = (1-c) * partition->size / 1024 / 1024;
             if (size < 1024){
                txtUsedSize->Text = "";
                txtUsedSize->Text = Convert::ToString((1-c) * partition->size / 1024 / 1024) + " MB";
             }
             else{
                 txtUsedSize->Text = "";
                 txtUsedSize->Text = Convert::ToString((1-c) * partition->size / 1024 / 1024 / 1024) + " GB";
             }
             size = (c) * partition->size/1024 /1024;
             if (size < 1024){
                txtFreeSize->Text = "";
                txtFreeSize->Text = Convert::ToString((c) * partition->size/1024 /1024) + " MB";
             }
             else{
                 txtFreeSize->Text = "";
                 txtFreeSize->Text = Convert::ToString((c) * partition->size/1024 /1024 / 1024) + " GB";
             }
			 txtTotalCluster->Text = "";
			 txtTotalCluster->Text = Convert::ToString((long long)partition->totalNumberOfClusters);
		 }
private: System::Void cbHDisk_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 int index = cbHDisk->SelectedIndex;
			 extern DiskInfo diskInfo;

			 if (index < 0 || index > diskInfo.getHDisks().size()-1)
				 return;				 
			 HardiskInfo *disk = diskInfo.getHDisks()[index];

			 txtVendorId->Text = "";
			 txtVendorId->Text = gcnew String(disk->vendorId.c_str());
			 txtProductId->Text = "";
			 txtProductId->Text = gcnew String(disk->productId.c_str());
			 txtSerialNumber->Text = "";
			 txtSerialNumber->Text = gcnew String(disk->serialNumber.c_str());
			 txtBytePerSector->Text = "";				 
			 txtBytePerSector->Text = Convert::ToString((long long)disk->bytePerSector);
			 txtSectorPerTrack->Text = "";
			 txtSectorPerTrack->Text = Convert::ToString((long long) disk->sectorsPerTrack);
			 txtTrackPerCylinder->Text = "";
			 txtTrackPerCylinder->Text = Convert::ToString((long long) disk->tracksPerCylinder);
			 txtCylinders->Text = "";
			 txtCylinders->Text = Convert::ToString((long long) disk->cylinders);			 
             txtDiskSize->Text = "";
			 txtDiskSize->Text = Convert::ToString((long long) disk->diskSize / 1024 / 1024 / 1024) + " GB";
			 txtDiskType->Text = "";
			 switch (disk->driverType)
			 {
			 case 0: txtDiskType->Text = "Unknown"; break;
			 case 11: txtDiskType->Text = "Removable media other than floppy"; break;
			 case 12: txtDiskType->Text = "Fixed hard disk media"; break;
			 default: txtDiskType->Text = "Floppy or other";
			 }
		 }
};
}

