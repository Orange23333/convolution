using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

using Spire.Xls;

namespace ConvertSheetToEZ0
{
	class Program
	{
		static void Main(string[] args)
		{
			Workbook workbook = new Workbook();
			workbook.LoadFromFile("in.xlsx");


			//获取第一个工作表
			Worksheet mSheet = workbook.Worksheets["多选题"];
			Worksheet sSheet = workbook.Worksheets["单选题"];
			Worksheet jSheet = workbook.Worksheets["判断题"];

			WriteQuestionFIle(mSheet, "题库", "out.m.ez0.qstf");
			WriteQuestionFIle(sSheet, "题库", "out.s.ez0.qstf");
			WriteQuestionFIle(jSheet, "题库", "out.j.ez0.qstf");

			workbook.Dispose();
			Console.WriteLine("End.");

			Console.ReadLine();
		}

		private static void WriteQuestionFIle(Worksheet workSheet, string title, string path)
		{
			int i, j, l, lend, an, n;
			char[] ans;

			FileStream fs = new FileStream(path, FileMode.OpenOrCreate, FileAccess.Write);
			StreamWriter sw = new StreamWriter(fs);

			sw.WriteLine("@ez0");
			sw.WriteLine("\"{0}\"", title);
			sw.WriteLine(">\"{0}\"", Escape(GetValue(workSheet, 1, 1)));

			an = int.Parse(GetValue(workSheet, 2, 1));
			n = int.Parse(GetValue(workSheet, 2, 2 + an));

			ans = new char[an];
			for (i = 0; i < an; i++)
			{
				ans[i] = GetValue(workSheet, 2, 2 + i)[0];
			}

			for (l = 3, lend = 3 + n; l < lend; l++)
			{
				sw.WriteLine("\t>\"{0}\"", Escape(GetValue(workSheet, l, 1)));
				for (i = 1; i <= an; i++)
				{
					string _debug = Escape(GetValue(workSheet, l, i + i));
					sw.WriteLine("\t\t*\"{0}\"", Escape(GetValue(workSheet, l, i + 1)));
				}

				string thisAnswer = GetValue(workSheet, l, 2 + an);
				sw.Write("\t\t.");

				StringBuilder sb = new StringBuilder();
				for (i = 0; i < thisAnswer.Length; i++)
				{
					for(j = 0; j < ans.Length; j++)
					{
						if (ans[j] == thisAnswer[i])
						{
							sb.Append((j + 1).ToString() + ",");
						}
					}
				}
				if (sb.Length > 0)
				{
					sb.Remove(sb.Length - 1, 1);
					sw.Write(sb.ToString());
				}
				sw.WriteLine();


				sw.WriteLine("\t<");
			}

			sw.WriteLine("<");

			sw.Dispose();
			fs.Dispose();
		}

		private static string Escape(string origin)
		{
			return Regex.Replace(origin, "(\\|\")", "\\$1");
		}

		private static string GetValue(Worksheet workSheet, int line, int row)
		{
			return workSheet.Range[ToAlphaNumber(row) + line.ToString()].Value2.ToString();
		}

		private static string ToAlphaNumber(int n)
		{
			int temp;
			StringBuilder sb = new StringBuilder();

			while (n > 0){
				temp = n % 27;
				n /= 27;
				sb.Append((char)('A' + (temp - 1)));
			}

			return new string(sb.ToString().Reverse().ToArray());
		}
	}
}
