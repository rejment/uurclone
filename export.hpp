#pragma once


static char *tmplFile[112] =
{
	"<?xml version=\"1.0\" encoding=\"ISO-8859-1\" ?>\r\n",
	"<?mso-application progid=\"Excel.Sheet\"?>\r\n",
	"<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\r\n",
	" xmlns:o=\"urn:schemas-microsoft-com:office:office\"\r\n",
	" xmlns:x=\"urn:schemas-microsoft-com:office:excel\"\r\n",
	" xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"\r\n",
	" xmlns:html=\"http://www.w3.org/TR/REC-html40\">\r\n",
	" <DocumentProperties xmlns=\"urn:schemas-microsoft-com:office:office\">\r\n",
	"  <LastAuthor>UURClone 1.2</LastAuthor>\r\n",
	"  <Created>2000-00-00T12:00:00Z</Created>\r\n",
	"  <Version>11.6360</Version>\r\n",
	" </DocumentProperties>\r\n",
	" <ExcelWorkbook xmlns=\"urn:schemas-microsoft-com:office:excel\">\r\n",
	"  <WindowHeight>12015</WindowHeight>\r\n",
	"  <WindowWidth>21675</WindowWidth>\r\n",
	"  <WindowTopX>360</WindowTopX>\r\n",
	"  <WindowTopY>300</WindowTopY>\r\n",
	"  <ProtectStructure>False</ProtectStructure>\r\n",
	"  <ProtectWindows>False</ProtectWindows>\r\n",
	" </ExcelWorkbook>\r\n",
	" <Styles>\r\n",
	"  <Style ss:ID=\"Default\" ss:Name=\"Normal\">\r\n",
	"   <Alignment ss:Vertical=\"Bottom\"/>\r\n",
	"   <Borders/>\r\n",
	"   <Font/>\r\n",
	"   <Interior/>\r\n",
	"   <NumberFormat/>\r\n",
	"   <Protection/>\r\n",
	"  </Style>\r\n",
	"  <Style ss:ID=\"s21\">\r\n",
	"   <Borders>\r\n",
	"    <Border ss:Position=\"Bottom\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Left\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Right\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Top\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"   </Borders>\r\n",
	"   <Font x:Family=\"Swiss\" ss:Bold=\"1\"/>\r\n",
	"   <Interior ss:Color=\"#FFCC00\" ss:Pattern=\"Solid\"/>\r\n",
	"  </Style>\r\n",
	"  <Style ss:ID=\"s22\">\r\n",
	"   <Borders>\r\n",
	"    <Border ss:Position=\"Bottom\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Left\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Right\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Top\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"   </Borders>\r\n",
	"   <NumberFormat ss:Format=\"Short Date\"/>\r\n",
	"  </Style>\r\n",
	"  <Style ss:ID=\"s23\">\r\n",
	"   <Borders>\r\n",
	"    <Border ss:Position=\"Bottom\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Left\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Right\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Top\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"   </Borders>\r\n",
	"   <NumberFormat ss:Format=\"Short Time\"/>\r\n",
	"  </Style>\r\n",
	"  <Style ss:ID=\"s24\">\r\n",
	"   <Borders>\r\n",
	"    <Border ss:Position=\"Bottom\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Left\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Right\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"    <Border ss:Position=\"Top\" ss:LineStyle=\"Continuous\" ss:Weight=\"1\"/>\r\n",
	"   </Borders>\r\n",
	"  </Style>\r\n",
	" </Styles>\r\n",
	" <Worksheet ss:Name=\"uur2\">\r\n",
	"  <Names>\r\n",
	"   <NamedRange ss:Name=\"_FilterDatabase\" ss:RefersTo=\"=uur2!R1C1:R5000C5\"\r\n",
	"    ss:Hidden=\"1\"/>\r\n",
	"  </Names>\r\n",
	"  <Table ss:ExpandedColumnCount=\"5\" ss:ExpandedRowCount=\"5000\" x:FullColumns=\"1\"\r\n",
	"   x:FullRows=\"1\">\r\n",
	"   <Column ss:AutoFitWidth=\"0\" ss:Width=\"75\"/>\r\n",
	"   <Column ss:AutoFitWidth=\"0\" ss:Width=\"60\" ss:Span=\"1\"/>\r\n",
	"   <Column ss:Index=\"4\" ss:AutoFitWidth=\"0\" ss:Width=\"150\"/>\r\n",
	"   <Column ss:AutoFitWidth=\"0\" ss:Width=\"60\"/>\r\n",
	"   <Row>\r\n",
	"    <Cell ss:StyleID=\"s21\"><Data ss:Type=\"String\">Date</Data><NamedCell\r\n",
	"      ss:Name=\"_FilterDatabase\"/></Cell>\r\n",
	"    <Cell ss:StyleID=\"s21\"><Data ss:Type=\"String\">Time</Data><NamedCell\r\n",
	"      ss:Name=\"_FilterDatabase\"/></Cell>\r\n",
	"    <Cell ss:StyleID=\"s21\"><Data ss:Type=\"String\">Activity</Data><NamedCell\r\n",
	"      ss:Name=\"_FilterDatabase\"/></Cell>\r\n",
	"    <Cell ss:StyleID=\"s21\"><Data ss:Type=\"String\">Comment</Data><NamedCell\r\n",
	"      ss:Name=\"_FilterDatabase\"/></Cell>\r\n",
	"    <Cell ss:StyleID=\"s21\"><Data ss:Type=\"String\">Duration</Data><NamedCell\r\n",
	"      ss:Name=\"_FilterDatabase\"/></Cell>\r\n",
	"   </Row>\r\n",
	"  </Table>\r\n",
	"  <WorksheetOptions xmlns=\"urn:schemas-microsoft-com:office:excel\">\r\n",
	"   <Print>\r\n",
	"    <ValidPrinterInfo/>\r\n",
	"    <PaperSizeIndex>9</PaperSizeIndex>\r\n",
	"    <HorizontalResolution>600</HorizontalResolution>\r\n",
	"    <VerticalResolution>600</VerticalResolution>\r\n",
	"   </Print>\r\n",
	"   <Selected/>\r\n",
	"   <Panes>\r\n",
	"    <Pane>\r\n",
	"     <Number>3</Number>\r\n",
	"     <ActiveRow>1</ActiveRow>\r\n",
	"    </Pane>\r\n",
	"   </Panes>\r\n",
	"   <ProtectObjects>False</ProtectObjects>\r\n",
	"   <ProtectScenarios>False</ProtectScenarios>\r\n",
	"  </WorksheetOptions>\r\n",
	"  <AutoFilter x:Range=\"R1C1:R27C5\"\r\n",
	"   xmlns=\"urn:schemas-microsoft-com:office:excel\">\r\n",
	"  </AutoFilter>\r\n",
	" </Worksheet>\r\n",
	"</Workbook>\r\n"
};


struct ExcelExport
{
	static void Write(HANDLE file, char *str)
	{
		DWORD written;
		::WriteFile(file, str, (DWORD) strlen(str), &written, 0);
	}

	static char * getToken(char* &ptr, char *EOF)
	{
		char *start = ptr;
		for (;*ptr!='\t' && *ptr!='\n' && ptr<EOF; ptr++) if (*ptr=='\r') *ptr=0;

		if (ptr == EOF) return 0;
		*ptr++ = 0;
		return start;
	}
	
	static void Export(LPCSTR fname, LPCSTR log)
	{
		File f;
		if (!f.Read(log)) return;
		if (f.GetFileSize() == 0) return;

		char *logfile = f;
		char *EOF = (char*)f + f.GetFileSize();

		HANDLE file = ::CreateFile(fname, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0,0);
		if (INVALID_HANDLE_VALUE != file)
		{
			for (int i=0; i<89; i++)
				Write(file, tmplFile[i]);

			char *tok = 0;
			while (true) {
				Write(file, "   <Row>\r\n");
				Write(file, "    <Cell ss:StyleID=\"s22\"><Data ss:Type=\"DateTime\">");
				if (!(tok = getToken(logfile, EOF))) break;
				Write(file, tok);
				Write(file, "T00:00:00.000</Data><NamedCell\r\n");
				Write(file, "      ss:Name=\"_FilterDatabase\"/></Cell>\r\n");
				Write(file, "    <Cell ss:StyleID=\"s23\"><Data ss:Type=\"DateTime\">1899-12-31T");
				if (!(tok = getToken(logfile, EOF))) break;
				Write(file, tok);				
				Write(file, ":00.000</Data><NamedCell\r\n");
				Write(file, "      ss:Name=\"_FilterDatabase\"/></Cell>\r\n");
				Write(file, "    <Cell ss:StyleID=\"s24\"><Data ss:Type=\"String\">");
				if (!(tok = getToken(logfile, EOF))) break;
				Write(file, tok);
				Write(file, "</Data><NamedCell\r\n");
				Write(file, "      ss:Name=\"_FilterDatabase\"/></Cell>\r\n");
				Write(file, "    <Cell ss:StyleID=\"s24\"><Data ss:Type=\"String\">");
				if (!(tok = getToken(logfile, EOF))) break;
				Write(file, tok);
				Write(file, "</Data><NamedCell\r\n");
				Write(file, "      ss:Name=\"_FilterDatabase\"/></Cell>\r\n");
				Write(file, "    <Cell ss:StyleID=\"s24\"><Data ss:Type=\"Number\">");
				if (!(tok = getToken(logfile, EOF))) break;
				for (int i=0; i<strlen(tok); i++) if (tok[i]==',') tok[i] = '.'; 
				Write(file, tok);
				Write(file, "</Data><NamedCell\r\n");
				Write(file, "      ss:Name=\"_FilterDatabase\"/></Cell>\r\n");
				Write(file, "   </Row>\r\n");
				if (logfile == EOF) break;
			}

			for (int i=89; i<112; i++)
				Write(file, tmplFile[i]);

			::CloseHandle(file);
		}
	}
};