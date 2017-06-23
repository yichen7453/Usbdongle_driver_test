#pragma once

#include "string_ctl.h"
#include "winsrv_ctl.h"

#define FRAME_WIDTH         128
#define FRAME_HEIGHT        128
#define FRAME_SIZE          (FRAME_WIDTH * FRAME_HEIGHT)

#define Synaptic_FRAME_WIDTH  144
#define Synaptic_FRAME_HEIGHT 56
#define Synaptic_FRAME_SIZE   (Synaptic_FRAME_WIDTH * Synaptic_FRAME_HEIGHT)

#define MAX_DEVPATH_LENGTH = 256;
#define countof(x) (sizeof(x) / sizeof(x[0]))

namespace USBDongle_driver_test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	using namespace System::Runtime::InteropServices;

	static HANDLE deviceHandle;

	static WINBIO_CAPTURE_PARAMETERS captureParams;
	static PWINBIO_CAPTURE_DATA captureData;
	static DWORD captureDataSize;

	static wchar_t deviceName[256];

	//BOOL	capture_data_result = FALSE;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//			
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnGetAttributes;
	protected:

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btnCaptureData;
	private: System::Windows::Forms::Button^  btnSensorState;
	private: System::Windows::Forms::Button^  btnCalibrate;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  lb_message;
	private: System::Windows::Forms::PictureBox^  pb_img;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  btnExit;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::ComponentModel::IContainer^  components;

	private:
		BOOL	capture_data_result;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnGetAttributes = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnCaptureData = (gcnew System::Windows::Forms::Button());
			this->btnSensorState = (gcnew System::Windows::Forms::Button());
			this->btnCalibrate = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lb_message = (gcnew System::Windows::Forms::Label());
			this->pb_img = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_img))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnGetAttributes
			// 
			this->btnGetAttributes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGetAttributes->Location = System::Drawing::Point(12, 24);
			this->btnGetAttributes->Name = L"btnGetAttributes";
			this->btnGetAttributes->Size = System::Drawing::Size(159, 40);
			this->btnGetAttributes->TabIndex = 0;
			this->btnGetAttributes->Text = L"Get Attributes";
			this->btnGetAttributes->UseVisualStyleBackColor = true;
			this->btnGetAttributes->Click += gcnew System::EventHandler(this, &MyForm::btnGetAttributes_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnCaptureData);
			this->groupBox1->Controls->Add(this->btnSensorState);
			this->groupBox1->Controls->Add(this->btnCalibrate);
			this->groupBox1->Controls->Add(this->btnReset);
			this->groupBox1->Controls->Add(this->btnGetAttributes);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(9, 9);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(190, 282);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"IOCTL function";
			// 
			// btnCaptureData
			// 
			this->btnCaptureData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCaptureData->Location = System::Drawing::Point(12, 232);
			this->btnCaptureData->Name = L"btnCaptureData";
			this->btnCaptureData->Size = System::Drawing::Size(159, 40);
			this->btnCaptureData->TabIndex = 4;
			this->btnCaptureData->Text = L"Capture Data";
			this->btnCaptureData->UseVisualStyleBackColor = true;
			this->btnCaptureData->Click += gcnew System::EventHandler(this, &MyForm::btnCaptureData_Click);
			// 
			// btnSensorState
			// 
			this->btnSensorState->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSensorState->Location = System::Drawing::Point(12, 180);
			this->btnSensorState->Name = L"btnSensorState";
			this->btnSensorState->Size = System::Drawing::Size(159, 40);
			this->btnSensorState->TabIndex = 3;
			this->btnSensorState->Text = L"Sensor Status";
			this->btnSensorState->UseVisualStyleBackColor = true;
			this->btnSensorState->Click += gcnew System::EventHandler(this, &MyForm::btnSensorState_Click);
			// 
			// btnCalibrate
			// 
			this->btnCalibrate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCalibrate->Location = System::Drawing::Point(12, 128);
			this->btnCalibrate->Name = L"btnCalibrate";
			this->btnCalibrate->Size = System::Drawing::Size(159, 40);
			this->btnCalibrate->TabIndex = 2;
			this->btnCalibrate->Text = L"Calibrate";
			this->btnCalibrate->UseVisualStyleBackColor = true;
			this->btnCalibrate->Click += gcnew System::EventHandler(this, &MyForm::btnCalibrate_Click);
			// 
			// btnReset
			// 
			this->btnReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReset->Location = System::Drawing::Point(12, 76);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(159, 40);
			this->btnReset->TabIndex = 1;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &MyForm::btnReset_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox2->Controls->Add(this->lb_message);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(206, 9);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(401, 282);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Message";
			// 
			// lb_message
			// 
			this->lb_message->BackColor = System::Drawing::Color::White;
			this->lb_message->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lb_message->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_message->Location = System::Drawing::Point(6, 23);
			this->lb_message->Name = L"lb_message";
			this->lb_message->Size = System::Drawing::Size(387, 246);
			this->lb_message->TabIndex = 1;
			this->lb_message->Text = L"USB fingerprint reader test for windows driver";
			this->lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pb_img
			// 
			this->pb_img->Location = System::Drawing::Point(11, 20);
			this->pb_img->Name = L"pb_img";
			this->pb_img->Size = System::Drawing::Size(193, 185);
			this->pb_img->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pb_img->TabIndex = 3;
			this->pb_img->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->pb_img);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(614, 9);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(212, 212);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Image";
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->Location = System::Drawing::Point(649, 238);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(159, 40);
			this->btnExit->TabIndex = 5;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker_Completed);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(837, 297);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"USBDongle_driver_test_1.5";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_Closed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_img))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnGetAttributes_Click(System::Object^  sender, System::EventArgs^  e) {
				 printf("\n  --> btnGetAttributes_Click() <-- \n");
							 
				 BOOL	bResult = TRUE;

				 WINBIO_SENSOR_ATTRIBUTES	sensorAttributes = { 0 };

				 DWORD	bytesReturned = 0;

				 DoStopSrv();

				 if (deviceHandle == NULL) {
				 	 deviceHandle = OpenDevice(FALSE);
				 }

				 if (deviceHandle == INVALID_HANDLE_VALUE) {
					 printf("\n btnGetAttributes_Click() : Unabled to find any devices.\n");
					 lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					 lb_message->Text = "Unabled to find any devices.";
					 deviceHandle = NULL;
				 }
				 else {
					 printf("\n IOCTL_BIOMETRIC_GET_ATTRIBUTES\n");

					 bResult = DeviceIoControl(deviceHandle, IOCTL_BIOMETRIC_GET_ATTRIBUTES, NULL, 0, &sensorAttributes, sizeof(WINBIO_SENSOR_ATTRIBUTES), &bytesReturned, NULL);

					 if (bResult) {
						 /*
						 printf("\n PayloadSize: %u\n", sensorAttributes.PayloadSize);
						 printf("\n WinBioHresult: %u\n", sensorAttributes.WinBioHresult);
						 printf("\n MajorVersion: %u\n", sensorAttributes.WinBioVersion.MajorVersion);
						 printf("\n MinorVersion: %u\n", sensorAttributes.WinBioVersion.MinorVersion);
					     printf("\n SensorType: %u\n", sensorAttributes.SensorType);
						 printf("\n SensorSubType: %u\n", sensorAttributes.SensorSubType);
						 printf("\n Capabilities: %u\n", sensorAttributes.Capabilities);
						 printf("\n ManufacturerName: %ls\n", sensorAttributes.ManufacturerName);
						 printf("\n ModelName: %ls\n", sensorAttributes.ModelName);
						 printf("\n SerialNumber: %ls\n", sensorAttributes.SerialNumber);
						 printf("\n FirmwareVersion: %u\n", sensorAttributes.FirmwareVersion.MajorVersion);
						 printf("\n FirmwareVersion: %u\n", sensorAttributes.FirmwareVersion.MinorVersion);
						 printf("\n SupportedFormatEntries: %u\n", sensorAttributes.SupportedFormatEntries);
						 */
						 lb_message->TextAlign = System::Drawing::ContentAlignment::TopLeft;
						 lb_message->Text = "\nIOCTL Get Attributes Information\n";
						 lb_message->Text += "  - PayloadSize: " + sensorAttributes.PayloadSize + "\n";
						 lb_message->Text += "  - Result: " + gcnew String(getResult(sensorAttributes.WinBioHresult)) + "\n";
						 lb_message->Text += "  - Version: [" + sensorAttributes.WinBioVersion.MajorVersion + "." + sensorAttributes.WinBioVersion.MinorVersion + "]\n";
						 lb_message->Text += "  - SensorType: " + gcnew String(getType(sensorAttributes.SensorType)) + "\n";
						 lb_message->Text += "  - SensorSubType: " + gcnew String(getSubType(sensorAttributes.SensorSubType)) + "\n";
						 lb_message->Text += "  - Capabilities: " + gcnew String(getCapabilities(sensorAttributes.Capabilities)) + "\n";
						 lb_message->Text += "  - Manufacturer: " + gcnew String(sensorAttributes.ManufacturerName) + "\n";
						 lb_message->Text += "  - Model: " + gcnew String(sensorAttributes.ModelName) + "\n";
						 lb_message->Text += "  - SerialNumber: " + gcnew String(sensorAttributes.SerialNumber) + "\n";
						 lb_message->Text += "  - FirmwareVersion: [" + sensorAttributes.FirmwareVersion.MajorVersion + "." + sensorAttributes.FirmwareVersion.MinorVersion + "]\n";
						 lb_message->Text += "  - SupportedFormatEntries: " + sensorAttributes.SupportedFormatEntries;						 						 
					 }

					 CloseHandle(deviceHandle);
					 deviceHandle = NULL;

					 printf("\n ============================\n");					
				 }
	}

	private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
				 printf("\n  --> btnReset_Click() <--  \n");

				 BOOL	bResult = TRUE;

				 WINBIO_BLANK_PAYLOAD blankPayload = { 0 };

				 DWORD	bytesReturned = 0;

				 DoStopSrv();

				 if (deviceHandle == NULL) {
					 deviceHandle = OpenDevice(FALSE);
				 }

				 if (deviceHandle == INVALID_HANDLE_VALUE) {
					 printf("\n Unalbed to find any devices\n");
					 lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					 lb_message->Text = "Unabled to find any devices.";
					 deviceHandle = NULL;
				 }
				 else {
					 printf("\n IOCTL_BIOMETRIC_RESET\n");
					 bResult = DeviceIoControl(deviceHandle, IOCTL_BIOMETRIC_RESET, NULL, 0, &blankPayload, sizeof(WINBIO_BLANK_PAYLOAD), &bytesReturned, NULL);

					 if (bResult) {
						 //printf("blankPayload PayloadSize: %d\n", blankPayload.PayloadSize);
						 //printf("blankPayload Hresult: %u\n", blankPayload.WinBioHresult);

						 lb_message->TextAlign = System::Drawing::ContentAlignment::TopLeft;
						 lb_message->Text = "\nIOCTL Reset Information\n";
						 lb_message->Text += "  - PayloadSize: " + blankPayload.PayloadSize + "\n";
						 lb_message->Text += "  - Result: " + gcnew String(getResult(blankPayload.WinBioHresult));
					 }

					 CloseHandle(deviceHandle);
					 deviceHandle = NULL;

					 printf("\n ============================\n");					 
				 }
	}

	private: System::Void btnCalibrate_Click(System::Object^  sender, System::EventArgs^  e) {
				 printf("\n  --> btnCalibrate_Click() <-- \n");

				 BOOL	bResult = TRUE;

				 WINBIO_CALIBRATION_INFO calibrationInfo = { 0 };

				 DWORD	bytesReturned = 0;

				 DoStopSrv();

				 if (deviceHandle == NULL) {
					 deviceHandle = OpenDevice(FALSE);
				 }

				 if (deviceHandle == INVALID_HANDLE_VALUE) {
					 printf("\n Unalbed to find any devices\n");
					 lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					 lb_message->Text = "Unabled to find any devices.";
					 deviceHandle = NULL;
				 }
				 else {
					 printf("\n IOCTL_BIOMETRIC_CALIBRATE\n");
					 bResult = DeviceIoControl(deviceHandle, IOCTL_BIOMETRIC_CALIBRATE, NULL, 0, &calibrationInfo, sizeof(WINBIO_CALIBRATION_INFO), &bytesReturned, NULL);

					 if (bResult) {
						 //printf("calibrationInfo PayloadSize: %d\n", calibrationInfo.PayloadSize);
						 //printf("calibrationInfo Hresult: %u\n", calibrationInfo.WinBioHresult);

						 lb_message->TextAlign = System::Drawing::ContentAlignment::TopLeft;
						 lb_message->Text = "\nIOCTL Calibrate Information\n";
						 lb_message->Text += "  - PayloadSize: " + calibrationInfo.PayloadSize + "\n";
						 lb_message->Text += "  - Result: " + gcnew String(getResult(calibrationInfo.WinBioHresult));
					 }

					 CloseHandle(deviceHandle);
					 deviceHandle = NULL;

					 printf("\n ============================\n");					
				 }
	}

	private: System::Void btnSensorState_Click(System::Object^  sender, System::EventArgs^  e) {
				 printf("\n  --> btnSensorState_Click() <-- \n");

				 BOOL	bResult = TRUE;

				 WINBIO_DIAGNOSTICS diagnostics = { 0 };

				 DWORD	bytesReturned = 0;

				 DoStopSrv();

				 if (deviceHandle == NULL) {
					 deviceHandle = OpenDevice(FALSE);
				 }

				 if (deviceHandle == INVALID_HANDLE_VALUE) {
					 printf("\n Unalbed to find any devices\n");
					 lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					 lb_message->Text = "Unabled to find any devices.";
					 deviceHandle = NULL;
				 }
				 else {
					 printf("\n IOCTL_BIOMETRIC_GET_SENSOR_STATUS\n");
					 bResult = DeviceIoControl(deviceHandle, IOCTL_BIOMETRIC_GET_SENSOR_STATUS, NULL, 0, &diagnostics, sizeof(WINBIO_DIAGNOSTICS), &bytesReturned, NULL);

					 if (bResult) {
						 //printf("diagnostics PayloadSize: %d\n", diagnostics.PayloadSize);
						 //printf("diagnostics Hresult: %u\n", diagnostics.WinBioHresult);
						 //printf("diagnostics SensorStatus: %u\n", diagnostics.SensorStatus);

						 lb_message->TextAlign = System::Drawing::ContentAlignment::TopLeft;
						 lb_message->Text = "\nIOCTL Get SensorStatus Information\n";
						 lb_message->Text += "  - PayloadSize: " + diagnostics.PayloadSize + "\n";
						 lb_message->Text += "  - Result: " + gcnew String(getResult(diagnostics.WinBioHresult)) + "\n";
						 lb_message->Text += "  - SensorStatus: " + gcnew String(getSensorStatus(diagnostics.SensorStatus));
					 }

					 CloseHandle(deviceHandle);
					 deviceHandle = NULL;

					 printf("\n ============================\n");					
				 }
	}

	private: System::Void btnCaptureData_Click(System::Object^  sender, System::EventArgs^  e) {
				 printf("\n  --> btnCaptureData_Click() <-- \n");

				 HRESULT hr = S_OK;				

				 BOOL	bResult = TRUE;
				 BOOL   allocateBuffer = TRUE;	

				 WINBIO_BLANK_PAYLOAD blankPayload = { 0 };

				 captureParams = { 0 };
				 captureData = { 0 };
				 captureDataSize = 0;

				 DWORD	bytesReturned = 0;
				 DWORD	allocationSize = 0;

				 DoStopSrv();

				 if (btnCaptureData->Text == "Capture Data") {				 

					 if (deviceHandle == NULL) {
						 deviceHandle = OpenDevice(FALSE);
					 }

					 if (deviceHandle == INVALID_HANDLE_VALUE) {
						 printf("\n Unalbed to find any devices\n");
						 lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
						 lb_message->Text = "Unabled to find any devices.";
						 deviceHandle = NULL;
					 }
					 else {
						 if (GetDevicePath((LPGUID)&GUID_DEVINTERFACE_BIOMETRIC_READER, deviceName, countof(deviceName))) {
							 printf("\n IOCTL_BIOMETRIC_CAPTURE_DATA\n");

							 btnGetAttributes->Enabled = false;
							 btnReset->Enabled = false;
							 btnCalibrate->Enabled = false;
							 btnSensorState->Enabled = false;
							 btnCaptureData->Text = "Stop Capture";

							 pb_img->Image = nullptr;

							 lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
							 lb_message->Text = "Press finger to capture image on device.";

							 captureParams.PayloadSize = sizeof(WINBIO_CAPTURE_PARAMETERS);
							 captureParams.Purpose = WINBIO_PURPOSE_VERIFY;
							 captureParams.Format.Owner = WINBIO_ANSI_381_FORMAT_OWNER;
							 captureParams.Format.Type = WINBIO_ANSI_381_FORMAT_TYPE;
							 CopyMemory(&captureParams.VendorFormat, &GUID_DEVINTERFACE_BIOMETRIC_READER, sizeof(WINBIO_UUID));
							 captureParams.Flags = WINBIO_DATA_FLAG_RAW;

							 while (true) {
								 if (captureData == NULL) {
									 bResult = DeviceIoControl(deviceHandle, IOCTL_BIOMETRIC_CAPTURE_DATA, &captureParams, sizeof(WINBIO_CAPTURE_PARAMETERS), &allocationSize, sizeof(DWORD), &bytesReturned, NULL);

									 if (!bResult && GetLastError() == ERROR_IO_PENDING) {
										 SetLastError(ERROR_SUCCESS);

										 bResult = GetOverlappedResult(deviceHandle, NULL, &bytesReturned, TRUE);
									 }

									 if (allocationSize < sizeof(WINBIO_CAPTURE_DATA)) {
										 allocationSize = sizeof(WINBIO_CAPTURE_DATA);
									 }

									 captureData = (PWINBIO_CAPTURE_DATA)LocalAlloc(LMEM_FIXED, allocationSize);
									 if (!captureData) {
										 captureDataSize = 0;
									 }
									 captureDataSize = allocationSize;

									 break;
								 }
							 }

							 backgroundWorker1->RunWorkerAsync();
						 }
						 else {
							 lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
							 lb_message->Text = "Unabled to find any devices.";
							 deviceHandle = NULL;
						 }
					 }
				 }
				 else {
					 btnCaptureData->Text = "Capture Data";

					 backgroundWorker1->CancelAsync();

					 bResult = DeviceIoControl(deviceHandle, IOCTL_BIOMETRIC_RESET, NULL, 0, &blankPayload, sizeof(WINBIO_BLANK_PAYLOAD), &bytesReturned, NULL);

					 btnGetAttributes->Enabled = true;
					 btnReset->Enabled = true;
					 btnCalibrate->Enabled = true;
					 btnSensorState->Enabled = true;

					 lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					 lb_message->Text = "USB fingerprint reader test for windows driver";
				 }
	}

	private: System::Void backgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
				 //printf("\n backgroundWorker_DoWork()....\n");

				 capture_data_result = FALSE;
				 DWORD	bytesReturned = 0;

				 if (backgroundWorker1->CancellationPending == true) {
					 printf("\n backgroundWorker_DoWork()....true\n");
					 e->Cancel = true;
				 }
				 else {
					 printf("\n backgroundWorker_DoWork()....false\n");
					 capture_data_result = DeviceIoControl(deviceHandle, IOCTL_BIOMETRIC_CAPTURE_DATA, &captureParams, sizeof(WINBIO_CAPTURE_PARAMETERS), captureData, captureDataSize, &bytesReturned, NULL);
				 }
	}

	private: System::Void backgroundWorker_Completed(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
				 //printf("\n backgroundWorker_Completed()...\n");

				 uint8_t newData[20000];

				 cli::array<Byte>^ byteArray = gcnew cli::array<Byte>(FRAME_SIZE);

				 if (GetDevicePath((LPGUID)&GUID_DEVINTERFACE_BIOMETRIC_READER, deviceName, countof(deviceName))) {
					 printf("\n IOCTL_BIOMETRIC_CAPTURE_DATA\n");
					 if (e->Cancelled == false) {
						 if (capture_data_result || !capture_data_result && GetLastError() == ERROR_IO_PENDING) {
							 if (captureData != NULL) {
								 printf("\n Capture data success!\n");

								 //printf("captureData PayloadSize: %u\n", captureData->PayloadSize);
								 //printf("captureData WinBioHresult: 0x%x\n", captureData->WinBioHresult);
								 //printf("captureData SensorStatus: %u\n", captureData->SensorStatus);

								 lb_message->TextAlign = System::Drawing::ContentAlignment::TopLeft;
								 lb_message->Text = "\nIOCTL Capture Data Information\n";
								 lb_message->Text += "  - PayloadSize: " + captureData->PayloadSize + "\n";
								 lb_message->Text += "  - Result: " + gcnew String(getResult(captureData->WinBioHresult)) + "\n";
								 lb_message->Text += "  - SensorStatus: " + gcnew String(getSensorStatus(captureData->SensorStatus)) + "\n";

								 if (captureData->PayloadSize.ToString() == "16408") {
									 for (int i = 0; i < FRAME_SIZE; i++) {
										 newData[i] = captureData->CaptureData.Data[i];
									 }
									 Marshal::Copy((IntPtr)newData, byteArray, 0, FRAME_SIZE);
									 pb_img->Image = ToGrayBitmap(byteArray, FRAME_WIDTH, FRAME_HEIGHT);
								 }
								 else if (captureData->PayloadSize.ToString() == "16544") {
									 for (int i = 0; i < FRAME_SIZE; i++) {
										 newData[i] = captureData->CaptureData.Data[i + 136];
									 }
									 Marshal::Copy((IntPtr)newData, byteArray, 0, FRAME_SIZE);
									 pb_img->Image = ToGrayBitmap(byteArray, FRAME_WIDTH, FRAME_HEIGHT);
								 }
								 else if (captureData->PayloadSize.ToString() == "8567") {
									 for (int i = 0; i < Synaptic_FRAME_SIZE; i++) {
										 newData[i] = captureData->CaptureData.Data[i + 136];
									 }
									 Marshal::Copy((IntPtr)newData, byteArray, 0, Synaptic_FRAME_SIZE);
									 pb_img->Image = ToGrayBitmap(byteArray, Synaptic_FRAME_WIDTH, Synaptic_FRAME_HEIGHT);
								 }

								 //Marshal::Copy((IntPtr)newData, byteArray, 0, FRAME_SIZE);
								 //pb_img->Image = ToGrayBitmap(byteArray, FRAME_WIDTH, FRAME_HEIGHT);

								 backgroundWorker1->RunWorkerAsync();
							 }
						 }
					 }
				 }
				 else {
					 printf("\n IOCTL_BIOMETRIC_CAPTURE_DATA fail....\n");
					 btnCaptureData->Text = "Capture Data";

					 backgroundWorker1->CancelAsync();

					 btnGetAttributes->Enabled = true;
					 btnReset->Enabled = true;
					 btnCalibrate->Enabled = true;
					 btnSensorState->Enabled = true;

					 lb_message->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					 lb_message->Text = "Unabled to find any devices.";
					 CloseHandle(deviceHandle);
					 deviceHandle = NULL;
				 }
	}

	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {

				 MyForm::Close();

				 backgroundWorker1->CancelAsync();
	}

	public: static Bitmap^ ToGrayBitmap(cli::array<Byte>^ rawValues, int width, int height) {
				Bitmap^ bmp = gcnew Bitmap(width, height, System::Drawing::Imaging::PixelFormat::Format8bppIndexed);
				System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height);
				BitmapData^ bmpData = bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::WriteOnly, bmp->PixelFormat);

				int stride = bmpData->Stride;
				int offset = stride - width;
				IntPtr iptr = bmpData->Scan0;
				int scanBytes = stride * height;

				int posScan = 0, posReal = 0;

				cli::array<Byte>^ pixelValues = gcnew cli::array<Byte>(scanBytes);

				for (int x = 0; x < height; x++) {
					for (int y = 0; y < width; y++) {
						pixelValues[posScan++] = rawValues[posReal++];
					}
					posScan += offset;
				}

				Marshal::Copy(pixelValues, 0, iptr, scanBytes);
				bmp->UnlockBits(bmpData);


				ColorPalette^ temPalette;

				Bitmap^ tempBmp = gcnew Bitmap(1, 1, System::Drawing::Imaging::PixelFormat::Format8bppIndexed);
				temPalette = tempBmp->Palette;

				for (int i = 0; i < 256; i++) {
					temPalette->Entries[i] = Color::FromArgb(i, i, i);
				}

				bmp->Palette = temPalette;

				return bmp;
	}

	HANDLE 
		OpenDevice(
		_In_ BOOL Synchronous)
	{
			HANDLE hDev;

			wchar_t completeDeviceName[256];

			if (!GetDevicePath((LPGUID)&GUID_DEVINTERFACE_BIOMETRIC_READER, completeDeviceName, countof(completeDeviceName))) {
				return INVALID_HANDLE_VALUE;
			}

			printf("\n OpenDevice() : DeviceName = (%ls)\n", completeDeviceName);

			hDev = CreateFile(completeDeviceName,
				GENERIC_WRITE | GENERIC_READ,
				FILE_SHARE_WRITE | FILE_SHARE_READ,
				NULL,
				OPEN_EXISTING,
				((Synchronous ? FILE_ATTRIBUTE_NORMAL : FILE_FLAG_OVERLAPPED) | SECURITY_IMPERSONATION),
				NULL);

			if (hDev == INVALID_HANDLE_VALUE) {
				printf("\n OpenDevice() : Failed to open the device, error - %d\n", GetLastError());
			}
			else {
				printf("\n OpenDevice() : Open device success.\n");
			}

			return hDev;
	}

	
	_Success_(return != FALSE)
	BOOL 
	GetDevicePath(
		_In_ LPGUID InterfaceGuid,
		_Out_writes_(BufLen) PTCHAR DevicePath,
		_In_ size_t BufLen) 
	{
			HDEVINFO							HardwareDeviceInfo;
			SP_DEVICE_INTERFACE_DATA			DeviceInterfaceData;
			PSP_DEVICE_INTERFACE_DETAIL_DATA	DeviceInterfaceDetailData = NULL;
			ULONG								Length, RequiredLength = 0;
			BOOL								bResult;
			HRESULT								hr;

			HardwareDeviceInfo = SetupDiGetClassDevs(InterfaceGuid, NULL, NULL, (DIGCF_PRESENT | DIGCF_DEVICEINTERFACE));

			if (HardwareDeviceInfo == NULL) {
				printf("\n GetDevicePath() : SetupDiGetClassDevs failed!\n");
				return FALSE;
			}

			DeviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

			bResult = SetupDiEnumDeviceInterfaces(HardwareDeviceInfo, 0, InterfaceGuid, 0, &DeviceInterfaceData);

			if (bResult == FALSE) {
				LPVOID lpMsgBuf;

				if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
					NULL,
					GetLastError(),
					MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
					(LPTSTR)&lpMsgBuf,
					0,
					NULL)) {

					//printf(" SetupDiEnumInterfaces failed: %s\n", (LPSTR)lpMsgBuf);
					printf("\n GetDevicePath() : SetupDiEnumInterfaces, error - %d\n", GetLastError());
					LocalFree(lpMsgBuf);
				}

				SetupDiDestroyDeviceInfoList(HardwareDeviceInfo);
				return FALSE;
			}

			SetupDiGetDeviceInterfaceDetail(HardwareDeviceInfo, &DeviceInterfaceData, NULL, 0, &RequiredLength, NULL);

			DeviceInterfaceDetailData = (PSP_DEVICE_INTERFACE_DETAIL_DATA)LocalAlloc(LMEM_FIXED, RequiredLength);

			if (DeviceInterfaceDetailData == NULL) {
				SetupDiDestroyDeviceInfoList(HardwareDeviceInfo);
				printf("\n GetDevicePath() : Failed to allocate memory.\n");
				return FALSE;
			}

			DeviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

			Length = RequiredLength;

			bResult = SetupDiGetDeviceInterfaceDetail(HardwareDeviceInfo, &DeviceInterfaceData, DeviceInterfaceDetailData, Length, &RequiredLength, NULL);
		
			if (bResult == FALSE) {

				LPVOID lpMsgBuf;

				if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
					NULL,
					GetLastError(),
					MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
					(LPTSTR)&lpMsgBuf,
					0,
					NULL)) {

					printf("\n GetDevicePath() : SetupDiEnumInterfaces failed: %s\n", (LPSTR)lpMsgBuf);
					LocalFree(lpMsgBuf);
				}

				SetupDiDestroyDeviceInfoList(HardwareDeviceInfo);
				LocalFree(DeviceInterfaceDetailData);
				return FALSE;
			}			

			hr = StringCchCopy(DevicePath, BufLen, DeviceInterfaceDetailData->DevicePath);
			if (FAILED(hr)) {
				SetupDiDestroyDeviceInfoList(HardwareDeviceInfo);
				LocalFree(DeviceInterfaceDetailData);
				return FALSE;
			}

			SetupDiDestroyDeviceInfoList(HardwareDeviceInfo);
			LocalFree(DeviceInterfaceDetailData);

			return TRUE;
	}

	private: System::Void MyForm_Closed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 CloseHandle(deviceHandle);
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 backgroundWorker1->WorkerSupportsCancellation = true;
	}
};
}
