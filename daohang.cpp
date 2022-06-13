#include"daohang.h"

void Function::init1() {
	//组存储相关信息
	//校本部
	ve[0] = { "校本部快递站", 0, " " };
	ve[1] = { "东门", 1, " " };
	ve[2] = { "学十公寓", 2, " " };
	ve[3] = { "经管楼", 3, " " };
	ve[4] = { "留学生公寓", 4, " " };
	ve[5] = { "食尚餐厅", 5, " " };
	ve[6] = { "学生科协", 6, " " };
	ve[7] = { "科研大楼", 7, " " };
	ve[8] = { "爱先蜂", 8, " " };
	ve[9] = { "学八公寓", 9, " " };
	ve[10] = { "漫咖啡", 10, " " };
	ve[11] = { "本部教工餐厅", 11, " " };
	ve[12] = { "本部学生餐厅", 12, " " };
	ve[13] = { "保卫处", 13, " " };
	ve[14] = { "学13公寓", 14, " " };
	ve[15] = { "学八宿舍楼", 15, " " };
	ve[16] = { "粤苑公寓", 16, " " };
	ve[17] = { "图书馆", 17, " " };
	ve[18] = { "篮球场", 18, " " };
	ve[19] = { "学29宿舍楼", 19, " " };
	ve[20] = { "学生二公寓", 20, " " };
	ve[21] = { "学苑餐厅", 21, " " };
	ve[22] = { "后勤楼", 22, " " };
	ve[23] = { "主楼", 23, " " };
	ve[24] = { "科学会堂", 24, " " };
	ve[25] = { "体育馆", 25, " " };
	ve[26] = { "体育部", 26, " " };
	ve[27] = { "教二楼", 27, " " };
	ve[28] = { "主席像", 28, " " };
	ve[29] = { "教三楼", 29, " " };
	ve[30] = { "西门", 30, " " };
	ve[31] = { "通信网络综合技术研究所", 31, " " };
	ve[32] = { "社区卫生服务中心", 32, " " };
	ve[33] = { "14号楼", 33, " " };
	ve[34] = { "南区娱乐中心", 34, " " };
	ve[35] = { "北邮家属院", 35, " " };
	ve[36] = { "北邮幼儿园", 36, " " };
	ve[37] = { "中国邮政", 37, " " };
	ve[38] = { "教四楼",38, " " };

	//邻接矩阵存储 
	weight[0][1] = weight[1][0] = 147;
	weight[0][2] = weight[2][0] = 76;
	weight[0][3] = weight[3][0] = 45;
	weight[1][2] = weight[2][1] = 89;
	weight[1][4] = weight[4][1] = 63;
	weight[2][3] = weight[3][2] = 69;
	weight[2][4] = weight[4][2] = 83;
	weight[2][5] = weight[5][2] = 47;
	weight[3][6] = weight[6][3] = 67;
	weight[3][7] = weight[7][3] = 149;
	weight[4][5] = weight[5][4] = 63;
	weight[4][8] = weight[8][4] = 54;
	weight[6][5] = weight[5][6] = 53;
	weight[5][9] = weight[9][5] = 45;
	weight[6][10] = weight[10][6] = 37;
	weight[8][9] = weight[9][8] = 74;
	weight[8][14] = weight[14][8] = 62;
	weight[8][15] = weight[15][8] = 48;
	weight[9][10] = weight[10][9] = 78;
	weight[10][7] = weight[7][10] = 154;
	weight[10][16] = weight[16][10] = 102;
	weight[10][17] = weight[17][10] = 104;
	weight[10][11] = weight[11][10] = 77;
	weight[7][11] = weight[11][7] = 104;
	weight[7][12] = weight[12][7] = 108;
	weight[14][15] = weight[15][14] = 88;
	weight[14][20] = weight[20][14] = 79;
	weight[15][16] = weight[16][15] = 47;
	weight[16][17] = weight[17][16] = 91;
	weight[16][21] = weight[21][16] = 61;
	weight[11][12] = weight[12][11] = 61;
	weight[11][17] = weight[17][11] = 104;
	weight[11][18] = weight[18][11] = 104;
	weight[12][17] = weight[17][12] = 128;
	weight[12][18] = weight[18][12] = 73;
	weight[12][13] = weight[13][12] = 132;
	weight[13][18] = weight[18][13] = 150;
	weight[13][19] = weight[19][13] = 33;
	weight[17][18] = weight[18][17] = 101;
	weight[17][21] = weight[21][17] = 99;
	weight[17][22] = weight[22][17] = 76;
	weight[18][22] = weight[22][18] = 137;
	weight[18][19] = weight[19][18] = 141;
	weight[18][25] = weight[25][18] = 92;
	weight[18][24] = weight[24][18] = 159;
	weight[19][25] = weight[25][19] = 146;
	weight[20][21] = weight[21][20] = 73;
	weight[20][30] = weight[30][20] = 162;
	weight[20][38] = weight[38][20] = 81;
	weight[21][38] = weight[38][21] = 75;
	weight[21][22] = weight[22][21] = 81;
	weight[38][30] = weight[30][38] = 124;
	weight[38][28] = weight[28][38] = 75;
	weight[38][22] = weight[22][38] = 107;
	weight[38][23] = weight[23][38] = 180;
	weight[22][28] = weight[28][22] = 147;
	weight[22][23] = weight[23][22] = 108;
	weight[22][24] = weight[24][22] = 153;
	weight[22][25] = weight[25][22] = 159;
	weight[25][24] = weight[24][25] = 81;
	weight[30][28] = weight[28][30] = 90;
	weight[30][33] = weight[33][30] = 137;
	weight[30][29] = weight[29][30] = 114;
	weight[28][29] = weight[29][28] = 80;
	weight[28][23] = weight[23][28] = 174;
	weight[28][27] = weight[27][28] = 159;
	weight[23][27] = weight[27][23] = 98;
	weight[23][24] = weight[24][23] = 56;
	weight[23][26] = weight[26][23] = 111;
	weight[24][26] = weight[26][24] = 60;
	weight[27][26] = weight[26][27] = 142;
	weight[31][26] = weight[26][31] = 83;
	weight[31][27] = weight[27][31] = 84;
	weight[27][37] = weight[37][27] = 79;
	weight[29][33] = weight[33][29] = 71;
	weight[29][37] = weight[37][29] = 104;
	weight[29][32] = weight[32][29] = 73;
	weight[29][27] = weight[27][29] = 142;
	weight[32][37] = weight[37][32] = 48;
	weight[32][33] = weight[33][32] = 82;
	weight[34][33] = weight[33][34] = 111;
	weight[32][34] = weight[34][32] = 52;
	weight[32][35] = weight[35][32] = 72;
	weight[34][35] = weight[35][34] = 43;
	weight[37][35] = weight[35][37] = 49;
	weight[36][35] = weight[35][36] = 107;
	weight[36][37] = weight[37][36] = 131;


	//沙河校区
	ve[39] = { "沙河快递站", 39, " " };
	ve[40] = { "足球场", 40, " " };
	ve[41] = { "篮球场", 41, " " };
	ve[42] = { "雁北A楼", 42, " " };
	ve[43] = { "雁北B楼", 43, " " };
	ve[44] = { "雁北C楼", 44, " " };
	ve[45] = { "雁北D1楼", 45, " " };
	ve[46] = { "雁北E楼", 46, " " };
	ve[47] = { "雁北D2楼",47, " " };
	ve[48] = { "信息楼S1",48, " " };
	ve[49] = { "S2区",49, " " };
	ve[50] = { "S3区",50, " " };
	ve[51] = { "S4区",51, " " };
	ve[52] = { "S5区",52, " " };
	ve[53] = { "S6区",53, " " };
	ve[54] = { "沙河教工食堂",54, " " };
	ve[55] = { "沙河学生食堂",55, " " };
	ve[56] = { "综合办公楼",56, " " };
	ve[57] = { "学生活动中心",57, " " };
	ve[58] = { "邮局",58, " " };
	ve[59] = { "南区食堂",59, " " };
	ve[60] = { "沙河图书馆",60, " " };
	ve[61] = { "东配楼",61, " " };
	ve[62] = { "咖啡厅",62, " " };
	ve[63] = { "N楼",63, " " };
	ve[64] = { "S楼",64, " " };
	ve[65] = { "西景观湖",65, " " };
	ve[66] = { "东景观湖",66, " " };
	ve[67] = { "教室楼S1",67, " " };
	ve[68] = { "实验楼S2,S3",68, " " };



	weight[39][41] = weight[41][39] = 284;
	weight[39][42] = weight[42][39] = 362;
	weight[39][48] = weight[48][39] = 399;
	weight[41][40] = weight[40][41] = 92;
	weight[41][42] = weight[42][41] = 77;
	weight[41][43] = weight[43][41] = 87;
	weight[41][46] = weight[46][41] = 118;
	weight[41][48] = weight[48][41] = 124;
	weight[42][48] = weight[48][42] = 55;
	weight[42][43] = weight[43][42] = 51;
	weight[42][45] = weight[45][42] = 86;
	weight[43][44] = weight[44][43] = 68;
	weight[43][46] = weight[46][43] = 56;
	weight[43][47] = weight[47][43] = 92;
	weight[44][47] = weight[47][44] = 58;
	weight[44][48] = weight[48][44] = 94;
	weight[44][45] = weight[45][44] = 37;
	weight[44][55] = weight[55][44] = 57;
	weight[44][54] = weight[54][44] = 61;
	weight[45][48] = weight[48][45] = 55;
	weight[45][55] = weight[55][45] = 49;
	weight[45][49] = weight[49][45] = 80;
	weight[45][54] = weight[54][45] = 84;
	weight[46][47] = weight[47][46] = 87;
	weight[47][54] = weight[54][47] = 55;
	weight[47][55] = weight[55][47] = 77;
	weight[48][55] = weight[55][48] = 106;
	weight[48][54] = weight[54][48] = 150;
	weight[48][57] = weight[57][48] = 155;
	weight[48][49] = weight[49][48] = 53;
	weight[49][55] = weight[55][49] = 95;
	weight[49][54] = weight[54][49] = 149;
	weight[49][50] = weight[50][49] = 36;
	weight[49][57] = weight[57][49] = 153;
	weight[49][58] = weight[58][49] = 127;
	weight[49][60] = weight[60][49] = 265;
	weight[49][63] = weight[63][49] = 252;
	weight[50][51] = weight[51][50] = 39;
	weight[51][52] = weight[52][51] = 31;
	weight[51][65] = weight[65][51] = 160;
	weight[52][53] = weight[53][52] = 30;
	weight[52][65] = weight[65][52] = 150;
	weight[53][59] = weight[59][53] = 98;
	weight[53][65] = weight[65][53] = 135;
	weight[53][65] = weight[65][53] = 135;
	weight[65][64] = weight[64][65] = 126;
	weight[65][66] = weight[66][65] = 103;
	weight[54][55] = weight[55][54] = 57;
	weight[54][56] = weight[56][54] = 71;
	weight[54][57] = weight[57][54] = 78;
	weight[54][58] = weight[58][54] = 102;
	weight[55][58] = weight[58][55] = 57;
	weight[55][56] = weight[56][55] = 87;
	weight[55][57] = weight[57][55] = 75;
	weight[56][57] = weight[57][56] = 30;
	weight[56][60] = weight[60][56] = 131;
	weight[56][58] = weight[58][56] = 79;
	weight[57][58] = weight[58][57] = 10;
	weight[57][60] = weight[60][57] = 127;
	weight[57][63] = weight[63][57] = 110;
	weight[57][64] = weight[64][57] = 165;
	weight[60][61] = weight[61][60] = 67;
	weight[60][63] = weight[63][60] = 91;
	weight[60][62] = weight[62][60] = 72;
	weight[61][62] = weight[62][61] = 53;
	weight[62][63] = weight[63][62] = 105;
	weight[62][67] = weight[67][62] = 114;
	weight[63][67] = weight[67][63] = 136;
	weight[63][64] = weight[64][63] = 57;
	weight[63][68] = weight[68][63] = 178;
	weight[64][68] = weight[68][64] = 153;
	weight[64][67] = weight[67][64] = 150;
	weight[64][66] = weight[66][64] = 57;
	weight[66][68] = weight[68][66] = 139;
	weight[66][67] = weight[67][66] = 191;
	weight[68][67] = weight[67][68] = 144;
}
void Function::init2() {
	//组存储相关信息
	//校本部
	ve[0] = { "校本部快递站", 0, " " };
	ve[1] = { "东门", 1, " " };
	ve[2] = { "学十公寓", 2, " " };
	ve[3] = { "经管楼", 3, " " };
	ve[4] = { "留学生公寓", 4, " " };
	ve[5] = { "食尚餐厅", 5, " " };
	ve[6] = { "学生科协", 6, " " };
	ve[7] = { "科研大楼", 7, " " };
	ve[8] = { "爱先蜂", 8, " " };
	ve[9] = { "学八公寓", 9, " " };
	ve[10] = { "漫咖啡", 10, " " };
	ve[11] = { "本部教工餐厅", 11, " " };
	ve[12] = { "本部学生餐厅", 12, " " };
	ve[13] = { "保卫处", 13, " " };
	ve[14] = { "学13公寓", 14, " " };
	ve[15] = { "学八宿舍楼", 15, " " };
	ve[16] = { "粤苑公寓", 16, " " };
	ve[17] = { "图书馆", 17, " " };
	ve[18] = { "篮球场", 18, " " };
	ve[19] = { "学29宿舍楼", 19, " " };
	ve[20] = { "学生二公寓", 20, " " };
	ve[21] = { "学苑餐厅", 21, " " };
	ve[22] = { "后勤楼", 22, " " };
	ve[23] = { "主楼", 23, " " };
	ve[24] = { "科学会堂", 24, " " };
	ve[25] = { "体育馆", 25, " " };
	ve[26] = { "体育部", 26, " " };
	ve[27] = { "教二楼", 27, " " };
	ve[28] = { "主席像", 28, " " };
	ve[29] = { "教三楼", 29, " " };
	ve[30] = { "西门", 30, " " };
	ve[31] = { "通信网络综合技术研究所", 31, " " };
	ve[32] = { "社区卫生服务中心", 32, " " };
	ve[33] = { "14号楼", 33, " " };
	ve[34] = { "南区娱乐中心", 34, " " };
	ve[35] = { "北邮家属院", 35, " " };
	ve[36] = { "北邮幼儿园", 36, " " };
	ve[37] = { "中国邮政", 37, " " };
	ve[38] = { "教四楼",38, " " };

	//邻接矩阵存储 
	weight[0][1] = weight[1][0] = 147 / 1.3;
	weight[0][2] = weight[2][0] = 76 / 1.3;
	weight[0][3] = weight[3][0] = 45 / (1.3 * 0.9);
	weight[1][2] = weight[2][1] = 89 / (1.3 * 0.85);
	weight[1][4] = weight[4][1] = 63 / (1.3 * 0.85);
	weight[2][3] = weight[3][2] = 69 / (1.3 * 0.9);
	weight[2][4] = weight[4][2] = 83 / (1.3 * 0.9);
	weight[2][5] = weight[5][2] = 47 / (1.3 * 0.7);
	weight[3][6] = weight[6][3] = 67 / (1.3 * 0.8);
	weight[3][7] = weight[7][3] = 149 / (1.3 * 0.8);
	weight[4][5] = weight[5][4] = 63 / (1.3 * 0.7);
	weight[4][8] = weight[8][4] = 54 / (1.3 * 0.7);
	weight[6][5] = weight[5][6] = 53 / (1.3 * 0.6);
	weight[5][9] = weight[9][5] = 45 / (1.3 * 0.8);
	weight[6][10] = weight[10][6] = 37 / (1.3 * 0.7);
	weight[8][9] = weight[9][8] = 74 / (1.3 * 0.9);
	weight[8][14] = weight[14][8] = 62 / (1.3 * 0.9);
	weight[8][15] = weight[15][8] = 48 / (1.3 * 0.9);
	weight[9][10] = weight[10][9] = 78 / (1.3 * 0.6);
	weight[10][7] = weight[7][10] = 154 / (1.3 * 0.9);
	weight[10][16] = weight[16][10] = 102 / (1.3 * 0.8);
	weight[10][17] = weight[17][10] = 104 / (1.3 * 0.7);
	weight[10][11] = weight[11][10] = 77 / (1.3 * 0.8);
	weight[7][11] = weight[11][7] = 104 / (1.3 * 0.9);
	weight[7][12] = weight[12][7] = 108 / (1.3 * 0.9);
	weight[14][15] = weight[15][14] = 88 / (1.3 * 1);
	weight[14][20] = weight[20][14] = 79 / (1.3 * 1);
	weight[15][16] = weight[16][15] = 47 / (1.3 * 1);
	weight[16][17] = weight[17][16] = 91 / (1.3 * 0.7);
	weight[16][21] = weight[21][16] = 61 / (1.3 * 0.7);
	weight[11][12] = weight[12][11] = 61 / (1.3 * 0.6);
	weight[11][17] = weight[17][11] = 104 / (1.3 * 0.6);
	weight[11][18] = weight[18][11] = 104 / (1.3 * 0.9);
	weight[12][17] = weight[17][12] = 128 / (1.3 * 0.6);
	weight[12][18] = weight[18][12] = 73 / (1.3 * 0.9);
	weight[12][13] = weight[13][12] = 132 / (1.3 * 0.8);
	weight[13][18] = weight[18][13] = 150 / (1.3 * 0.9);
	weight[13][19] = weight[19][13] = 33 / (1.3 * 1);
	weight[17][18] = weight[18][17] = 101 / (1.3 * 0.9);
	weight[17][21] = weight[21][17] = 99 / (1.3 * 0.8);
	weight[17][22] = weight[22][17] = 76 / (1.3 * 0.8);
	weight[18][22] = weight[22][18] = 137 / (1.3 * 0.9);
	weight[18][19] = weight[19][18] = 141 / (1.3 * 0.9);
	weight[18][25] = weight[25][18] = 92 / (1.3 * 0.9);
	weight[18][24] = weight[24][18] = 159 / (1.3 * 0.7);
	weight[19][25] = weight[25][19] = 146 / (1.3 * 0.9);
	weight[20][21] = weight[21][20] = 73 / (1.3 * 0.9);
	weight[20][30] = weight[30][20] = 162 / (1.3 * 0.9);
	weight[20][38] = weight[38][20] = 81 / (1.3 * 0.7);
	weight[21][38] = weight[38][21] = 75 / (1.3 * 0.7);
	weight[21][22] = weight[22][21] = 81 / (1.3 * 0.9);
	weight[38][30] = weight[30][38] = 124 / (1.3 * 0.8);
	weight[38][28] = weight[28][38] = 75 / (1.3 * 0.7);
	weight[38][22] = weight[22][38] = 107 / (1.3 * 0.9);
	weight[38][23] = weight[23][38] = 180 / (1.3 * 0.7);
	weight[22][28] = weight[28][22] = 147 / (1.3 * 0.8);
	weight[22][23] = weight[23][22] = 108 / (1.3 * 0.8);
	weight[22][24] = weight[24][22] = 153 / (1.3 * 0.9);
	weight[22][25] = weight[25][22] = 159 / (1.3 * 0.9);
	weight[25][24] = weight[24][25] = 81 / (1.3 * 0.9);
	weight[30][28] = weight[28][30] = 90 / (1.3 * 0.9);
	weight[30][33] = weight[33][30] = 137 / (1.3 * 0.9);
	weight[30][29] = weight[29][30] = 114 / (1.3 * 0.8);
	weight[28][29] = weight[29][28] = 80 / (1.3 * 0.7);
	weight[28][23] = weight[23][28] = 174 / (1.3 * 0.8);
	weight[28][27] = weight[27][28] = 159 / (1.3 * 0.8);
	weight[23][27] = weight[27][23] = 98 / (1.3 * 0.8);
	weight[23][24] = weight[24][23] = 56 / (1.3 * 0.9);
	weight[23][26] = weight[26][23] = 111 / (1.3 * 0.9);
	weight[24][26] = weight[26][24] = 60 / (1.3 * 0.9);
	weight[27][26] = weight[26][27] = 142 / (1.3 * 0.9);
	weight[31][26] = weight[26][31] = 83 / (1.3 * 0.9);
	weight[31][27] = weight[27][31] = 84 / (1.3 * 0.9);
	weight[27][37] = weight[37][27] = 79 / (1.3 * 0.7);
	weight[29][33] = weight[33][29] = 71 / (1.3 * 0.8);
	weight[29][37] = weight[37][29] = 104 / (1.3 * 0.7);
	weight[29][32] = weight[32][29] = 73 / (1.3 * 0.9);
	weight[29][27] = weight[27][29] = 142 / (1.3 * 0.7);
	weight[32][37] = weight[37][32] = 48 / (1.3 * 0.9);
	weight[32][33] = weight[33][32] = 82 / (1.3 * 0.9);
	weight[34][33] = weight[33][34] = 111 / (1.3 * 0.9);
	weight[32][34] = weight[34][32] = 52 / (1.3 * 0.9);
	weight[32][35] = weight[35][32] = 72 / (1.3 * 0.9);
	weight[34][35] = weight[35][34] = 43 / (1.3 * 0.9);
	weight[37][35] = weight[35][37] = 49 / (1.3 * 0.9);
	weight[36][35] = weight[35][36] = 107 / (1.3 * 0.9);
	weight[36][37] = weight[37][36] = 131 / (1.3 * 0.9);


	//沙河校区
	ve[39] = { "沙河快递站", 39, " " };
	ve[40] = { "足球场", 40, " " };
	ve[41] = { "篮球场", 41, " " };
	ve[42] = { "雁北A楼", 42, " " };
	ve[43] = { "雁北B楼", 43, " " };
	ve[44] = { "雁北C楼", 44, " " };
	ve[45] = { "雁北D1楼", 45, " " };
	ve[46] = { "雁北E楼", 46, " " };
	ve[47] = { "雁北D2楼",47, " " };
	ve[48] = { "信息楼S1",48, " " };
	ve[49] = { "S2区",49, " " };
	ve[50] = { "S3区",50, " " };
	ve[51] = { "S4区",51, " " };
	ve[52] = { "S5区",52, " " };
	ve[53] = { "S6区",53, " " };
	ve[54] = { "沙河教工食堂",54, " " };
	ve[55] = { "沙河学生食堂",55, " " };
	ve[56] = { "综合办公楼",56, " " };
	ve[57] = { "学生活动中心",57, " " };
	ve[58] = { "邮局",58, " " };
	ve[59] = { "南区食堂",59, " " };
	ve[60] = { "沙河图书馆",60, " " };
	ve[61] = { "东配楼",61, " " };
	ve[62] = { "咖啡厅",62, " " };
	ve[63] = { "N楼",63, " " };
	ve[64] = { "S楼",64, " " };
	ve[65] = { "西景观湖",65, " " };
	ve[66] = { "东景观湖",66, " " };
	ve[67] = { "教室楼S1",67, " " };
	ve[68] = { "实验楼S2,S3",68, " " };



	weight[39][41] = weight[41][39] = 284 / (1.3 * 1);
	weight[39][42] = weight[42][39] = 362 / (1.3 * 1);
	weight[39][48] = weight[48][39] = 399 / (1.3 * 1);
	weight[41][40] = weight[40][41] = 92 / (1.3 * 1);
	weight[41][42] = weight[42][41] = 77 / (1.3 * 1);
	weight[41][43] = weight[43][41] = 87 / (1.3 * 1);
	weight[41][46] = weight[46][41] = 118 / (1.3 * 1);
	weight[41][48] = weight[48][41] = 124 / (1.3 * 1);
	weight[42][48] = weight[48][42] = 55 / (1.3 * 1);
	weight[42][43] = weight[43][42] = 51 / (1.3 * 1);
	weight[42][45] = weight[45][42] = 86 / (1.3 * 1);
	weight[43][44] = weight[44][43] = 68 / (1.3 * 1);
	weight[43][46] = weight[46][43] = 56 / (1.3 * 1);
	weight[43][47] = weight[47][43] = 92 / (1.3 * 1);
	weight[44][47] = weight[47][44] = 58 / (1.3 * 1);
	weight[44][48] = weight[48][44] = 94 / (1.3 * 1);
	weight[44][45] = weight[45][44] = 37 / (1.3 * 1);
	weight[44][55] = weight[55][44] = 57 / (1.3 * 1);
	weight[44][54] = weight[54][44] = 61 / (1.3 * 1);
	weight[45][48] = weight[48][45] = 55 / (1.3 * 1);
	weight[45][55] = weight[55][45] = 49 / (1.3 * 1);
	weight[45][49] = weight[49][45] = 80 / (1.3 * 1);
	weight[45][54] = weight[54][45] = 84 / (1.3 * 1);
	weight[46][47] = weight[47][46] = 87 / (1.3 * 1);
	weight[47][54] = weight[54][47] = 55 / (1.3 * 1);
	weight[47][55] = weight[55][47] = 77 / (1.3 * 1);
	weight[48][55] = weight[55][48] = 106 / (1.3 * 1);
	weight[48][54] = weight[54][48] = 150 / (1.3 * 1);
	weight[48][57] = weight[57][48] = 155 / (1.3 * 1);
	weight[48][49] = weight[49][48] = 53 / (1.3 * 1);
	weight[49][55] = weight[55][49] = 95 / (1.3 * 1);
	weight[49][54] = weight[54][49] = 149 / (1.3 * 1);
	weight[49][50] = weight[50][49] = 36 / (1.3 * 1);
	weight[49][57] = weight[57][49] = 153 / (1.3 * 1);
	weight[49][58] = weight[58][49] = 127 / (1.3 * 1);
	weight[49][60] = weight[60][49] = 265 / (1.3 * 1);
	weight[49][63] = weight[63][49] = 252 / (1.3 * 1);
	weight[50][51] = weight[51][50] = 39 / (1.3 * 1);
	weight[51][52] = weight[52][51] = 31 / (1.3 * 1);
	weight[51][65] = weight[65][51] = 160 / (1.3 * 1);
	weight[52][53] = weight[53][52] = 30 / (1.3 * 1);
	weight[52][65] = weight[65][52] = 150 / (1.3 * 1);
	weight[53][59] = weight[59][53] = 98 / (1.3 * 1);
	weight[53][65] = weight[65][53] = 135 / (1.3 * 1);
	weight[53][65] = weight[65][53] = 135 / (1.3 * 1);
	weight[65][64] = weight[64][65] = 126 / (1.3 * 1);
	weight[65][66] = weight[66][65] = 103 / (1.3 * 1);
	weight[54][55] = weight[55][54] = 57 / (1.3 * 0.7);
	weight[54][56] = weight[56][54] = 71 / (1.3 * 1);
	weight[54][57] = weight[57][54] = 78 / (1.3 * 1);
	weight[54][58] = weight[58][54] = 102 / (1.3 * 1);
	weight[55][58] = weight[58][55] = 57 / (1.3 * 1);
	weight[55][56] = weight[56][55] = 87 / (1.3 * 1);
	weight[55][57] = weight[57][55] = 75 / (1.3 * 1);
	weight[56][57] = weight[57][56] = 30 / (1.3 * 1);
	weight[56][60] = weight[60][56] = 131 / (1.3 * 1);
	weight[56][58] = weight[58][56] = 79 / (1.3 * 1);
	weight[57][58] = weight[58][57] = 10 / (1.3 * 0.7);
	weight[57][60] = weight[60][57] = 127 / (1.3 * 1);
	weight[57][63] = weight[63][57] = 110 / (1.3 * 1);
	weight[57][64] = weight[64][57] = 165 / (1.3 * 1);
	weight[60][61] = weight[61][60] = 67 / (1.3 * 1);
	weight[60][63] = weight[63][60] = 91 / (1.3 * 1);
	weight[60][62] = weight[62][60] = 72 / (1.3 * 1);
	weight[61][62] = weight[62][61] = 53 / (1.3 * 1);
	weight[62][63] = weight[63][62] = 105 / (1.3 * 1);
	weight[62][67] = weight[67][62] = 114 / (1.3 * 1);
	weight[63][67] = weight[67][63] = 136 / (1.3 * 1);
	weight[63][64] = weight[64][63] = 57 / (1.3 * 0.7);
	weight[63][68] = weight[68][63] = 178 / (1.3 * 1);
	weight[64][68] = weight[68][64] = 153 / (1.3 * 1);
	weight[64][67] = weight[67][64] = 150 / (1.3 * 1);
	weight[64][66] = weight[66][64] = 57 / (1.3 * 1);
	weight[66][68] = weight[68][66] = 139 / (1.3 * 1);
	weight[66][67] = weight[67][66] = 191 / (1.3 * 1);
	weight[68][67] = weight[67][68] = 144 / (1.3 * 1);
}
void Function::init3() {
	//组存储相关信息
	//沙河校区
	ve[0] = { "校本部快递站", 0, " " };
	ve[1] = { "东门", 1, " " };
	ve[2] = { "学十公寓", 2, " " };
	ve[3] = { "经管楼", 3, " " };
	ve[4] = { "留学生公寓", 4, " " };
	ve[5] = { "食尚餐厅", 5, " " };
	ve[6] = { "学生科协", 6, " " };
	ve[7] = { "科研大楼", 7, " " };
	ve[8] = { "爱先蜂", 8, " " };
	ve[9] = { "学八公寓", 9, " " };
	ve[10] = { "漫咖啡", 10, " " };
	ve[11] = { "本部教工餐厅", 11, " " };
	ve[12] = { "本部学生餐厅", 12, " " };
	ve[13] = { "保卫处", 13, " " };
	ve[14] = { "学13公寓", 14, " " };
	ve[15] = { "学八宿舍楼", 15, " " };
	ve[16] = { "粤苑公寓", 16, " " };
	ve[17] = { "图书馆", 17, " " };
	ve[18] = { "篮球场", 18, " " };
	ve[19] = { "学29宿舍楼", 19, " " };
	ve[20] = { "学生二公寓", 20, " " };
	ve[21] = { "学苑餐厅", 21, " " };
	ve[22] = { "后勤楼", 22, " " };
	ve[23] = { "主楼", 23, " " };
	ve[24] = { "科学会堂", 24, " " };
	ve[25] = { "体育馆", 25, " " };
	ve[26] = { "体育部", 26, " " };
	ve[27] = { "教二楼", 27, " " };
	ve[28] = { "主席像", 28, " " };
	ve[29] = { "教三楼", 29, " " };
	ve[30] = { "西门", 30, " " };
	ve[31] = { "通信网络综合技术研究所", 31, " " };
	ve[32] = { "社区卫生服务中心", 32, " " };
	ve[33] = { "14号楼", 33, " " };
	ve[34] = { "南区娱乐中心", 34, " " };
	ve[35] = { "北邮家属院", 35, " " };
	ve[36] = { "北邮幼儿园", 36, " " };
	ve[37] = { "中国邮政", 37, " " };
	ve[38] = { "教四楼",38, " " };
	//校本部
	ve[39] = { "沙河快递站", 39, " " };
	ve[40] = { "足球场", 40, " " };
	ve[41] = { "篮球场", 41, " " };
	ve[42] = { "雁北A楼", 42, " " };
	ve[43] = { "雁北B楼", 43, " " };
	ve[44] = { "雁北C楼", 44, " " };
	ve[45] = { "雁北D1楼", 45, " " };
	ve[46] = { "雁北E楼", 46, " " };
	ve[47] = { "雁北D2楼",47, " " };
	ve[48] = { "信息楼S1",48, " " };
	ve[49] = { "S2区",49, " " };
	ve[50] = { "S3区",50, " " };
	ve[51] = { "S4区",51, " " };
	ve[52] = { "S5区",52, " " };
	ve[53] = { "S6区",53, " " };
	ve[54] = { "沙河教工食堂",54, " " };
	ve[55] = { "沙河学生食堂",55, " " };
	ve[56] = { "综合办公楼",56, " " };
	ve[57] = { "学生活动中心",57, " " };
	ve[58] = { "邮局",58, " " };
	ve[59] = { "南区食堂",59, " " };
	ve[60] = { "沙河图书馆",60, " " };
	ve[61] = { "东配楼",61, " " };
	ve[62] = { "咖啡厅",62, " " };
	ve[63] = { "N楼",63, " " };
	ve[64] = { "S楼",64, " " };
	ve[65] = { "西景观湖",65, " " };
	ve[66] = { "东景观湖",66, " " };
	ve[67] = { "教室楼S1",67, " " };
	ve[68] = { "实验楼S2,S3",68, " " };

	//邻接矩阵存储 
		//沙河校区(因施工等原因暂不计入雁南楼的相关路径连接)
	//自行车正常速度为4.1 m/s,在校园内因安全问题应适量降低车速，故取基本正常行驶速度为3m/s.
	//拥挤度高于0.6时可认为自行车速度快，自行车与拥挤度的函数关系为 v = 3*x^3
	weight[39][41] = weight[41][39] = 284 / (3 * pow(1, 3));
	weight[39][42] = weight[42][39] = 362 / (3 * pow(1, 3));
	weight[39][48] = weight[48][39] = 399 / (3 * pow(1, 3));
	weight[41][40] = weight[40][41] = 92 / (3 * pow(1, 3));
	weight[41][42] = weight[42][41] = 77 / (3 * pow(1, 3));
	weight[41][43] = weight[43][41] = 87 / (3 * pow(1, 3));
	weight[41][46] = weight[46][41] = 118 / (3 * pow(1, 3));
	weight[41][48] = weight[48][41] = 124 / (3 * pow(1, 3));
	weight[42][48] = weight[48][42] = 55 / (3 * pow(1, 3));
	weight[42][43] = weight[43][42] = 51 / (3 * pow(1, 3));
	weight[42][45] = weight[45][42] = 86 / (3 * pow(1, 3));
	weight[43][44] = weight[44][43] = 68 / (3 * pow(1, 3));
	weight[43][46] = weight[46][43] = 56 / (3 * pow(1, 3));
	weight[43][47] = weight[47][43] = 92 / (3 * pow(1, 3));
	weight[44][47] = weight[47][44] = 58 / (3 * pow(1, 3));
	weight[44][48] = weight[48][44] = 94 / (3 * pow(1, 3));
	weight[44][45] = weight[45][44] = 37 / (3 * pow(1, 3));
	weight[44][55] = weight[55][44] = 57 / (3 * pow(1, 3));
	weight[44][54] = weight[54][44] = 61 / (3 * pow(1, 3));
	weight[45][48] = weight[48][45] = 55 / (3 * pow(1, 3));
	weight[45][55] = weight[55][45] = 49 / (3 * pow(1, 3));
	weight[45][49] = weight[49][45] = 80 / (3 * pow(1, 3));
	weight[45][54] = weight[54][45] = 84 / (3 * pow(1, 3));
	weight[46][47] = weight[47][46] = 87 / (3 * pow(1, 3));
	weight[47][54] = weight[54][47] = 55 / (3 * pow(1, 3));
	weight[47][55] = weight[55][47] = 77 / (3 * pow(1, 3));
	weight[48][55] = weight[55][48] = 106 / (3 * pow(1, 3));
	weight[48][54] = weight[54][48] = 150 / (3 * pow(1, 3));
	weight[48][57] = weight[57][48] = 155 / (3 * pow(1, 3));
	weight[48][49] = weight[49][48] = 53 / (3 * pow(1, 3));
	weight[49][55] = weight[55][49] = 95 / (3 * pow(1, 3));
	weight[49][54] = weight[54][49] = 149 / (3 * pow(1, 3));
	weight[49][50] = weight[50][49] = 36 / (3 * pow(1, 3));
	weight[49][57] = weight[57][49] = 153 / (3 * pow(1, 3));
	weight[49][58] = weight[58][49] = 127 / (3 * pow(1, 3));
	weight[49][60] = weight[60][49] = 265 / (3 * pow(1, 3));
	weight[49][63] = weight[63][49] = 252 / (3 * pow(1, 3));
	weight[50][51] = weight[51][50] = 39 / (3 * pow(1, 3));
	weight[51][52] = weight[52][51] = 31 / (3 * pow(1, 3));
	weight[51][65] = weight[65][51] = 160 / (3 * pow(1, 3));
	weight[52][53] = weight[53][52] = 30 / (3 * pow(1, 3));
	weight[52][65] = weight[65][52] = 150 / (3 * pow(1, 3));
	weight[53][59] = weight[59][53] = 98 / (3 * pow(1, 3));
	weight[53][65] = weight[65][53] = 135 / (3 * pow(1, 3));
	weight[53][65] = weight[65][53] = 135 / (3 * pow(1, 3));
	weight[65][64] = weight[64][65] = 126 / (3 * pow(1, 3));
	weight[65][66] = weight[66][65] = 103 / (3 * pow(1, 3));
	weight[54][55] = weight[55][54] = 57 / (3 * pow(0.7, 3));
	weight[54][56] = weight[56][54] = 71 / (3 * pow(1, 3));
	weight[54][57] = weight[57][54] = 78 / (3 * pow(1, 3));
	weight[54][58] = weight[58][54] = 102 / (3 * pow(1, 3));
	weight[55][58] = weight[58][55] = 57 / (3 * pow(1, 3));
	weight[55][56] = weight[56][55] = 87 / (3 * pow(1, 3));
	weight[55][57] = weight[57][55] = 75 / (3 * pow(1, 3));
	weight[56][57] = weight[57][56] = 30 / (3 * pow(1, 3));
	weight[56][60] = weight[60][56] = 131 / (3 * pow(1, 3));
	weight[56][58] = weight[58][56] = 79 / (3 * pow(1, 3));
	weight[57][58] = weight[58][57] = 10 / (3 * pow(0.7, 3));
	weight[57][60] = weight[60][57] = 127 / (3 * pow(1, 3));
	weight[57][63] = weight[63][57] = 110 / (3 * pow(1, 3));
	weight[57][64] = weight[64][57] = 165 / (3 * pow(1, 3));
	weight[60][61] = weight[61][60] = 67 / (3 * pow(1, 3));
	weight[60][63] = weight[63][60] = 91 / (3 * pow(1, 3));
	weight[60][62] = weight[62][60] = 72 / (3 * pow(1, 3));
	weight[61][62] = weight[62][61] = 53 / (3 * pow(1, 3));
	weight[62][63] = weight[63][62] = 105 / (3 * pow(1, 3));
	weight[62][67] = weight[67][62] = 114 / (3 * pow(1, 3));
	weight[63][67] = weight[67][63] = 136 / (3 * pow(1, 3));
	weight[63][64] = weight[64][63] = 57 / (3 * pow(0.7, 3));
	weight[63][68] = weight[68][63] = 178 / (3 * pow(1, 3));
	weight[64][68] = weight[68][64] = 153 / (3 * pow(1, 3));
	weight[64][67] = weight[67][64] = 150 / (3 * pow(1, 3));
	weight[64][66] = weight[66][64] = 57 / (3 * pow(1, 3));
	weight[66][68] = weight[68][66] = 139 / (3 * pow(1, 3));
	weight[66][67] = weight[67][66] = 191 / (3 * pow(1, 3));
	weight[68][67] = weight[67][68] = 144 / (3 * pow(1, 3));

	//校本部
	weight[0][1] = weight[1][0] = 147 / 3;
	weight[0][2] = weight[2][0] = 76 / 3;
	weight[0][3] = weight[3][0] = 45 / (3 * pow(0.9, 3));
	weight[1][2] = weight[2][1] = 89 / (3 * pow(0.85, 3));
	weight[1][4] = weight[4][1] = 63 / (3 * pow(0.85, 3));
	weight[2][3] = weight[3][2] = 69 / (3 * pow(0.9, 3));
	weight[2][4] = weight[4][2] = 83 / (3 * pow(0.9, 3));
	weight[2][5] = weight[5][2] = 47 / (3 * pow(0.7, 3));
	weight[3][6] = weight[6][3] = 67 / (3 * pow(0.8, 3));
	weight[3][7] = weight[7][3] = 149 / (3 * pow(0.8, 3));
	weight[4][5] = weight[5][4] = 63 / (3 * pow(0.7, 3));
	weight[4][8] = weight[8][4] = 54 / (3 * pow(0.7, 3));
	weight[6][5] = weight[5][6] = 53 / (1.3 * 0.6);
	weight[5][9] = weight[9][5] = 45 / (3 * pow(0.8, 3));
	weight[6][10] = weight[10][6] = 37 / (3 * pow(0.7, 3));
	weight[8][9] = weight[9][8] = 74 / (3 * pow(0.9, 3));
	weight[8][14] = weight[14][8] = 62 / (3 * pow(0.9, 3));
	weight[8][15] = weight[15][8] = 48 / (3 * pow(0.9, 3));
	weight[9][10] = weight[10][9] = 78 / (1.3 * 0.6);
	weight[10][7] = weight[7][10] = 154 / (3 * pow(0.9, 3));
	weight[10][16] = weight[16][10] = 102 / (3 * pow(0.8, 3));
	weight[10][17] = weight[17][10] = 104 / (3 * pow(0.7, 3));
	weight[10][11] = weight[11][10] = 77 / (3 * pow(0.8, 3));
	weight[7][11] = weight[11][7] = 104 / (3 * pow(0.9, 3));
	weight[7][12] = weight[12][7] = 108 / (3 * pow(0.9, 3));
	weight[14][15] = weight[15][14] = 88 / (3 * pow(1, 3));
	weight[14][20] = weight[20][14] = 79 / (3 * pow(1, 3));
	weight[15][16] = weight[16][15] = 47 / (3 * pow(1, 3));
	weight[16][17] = weight[17][16] = 91 / (3 * pow(0.7, 3));
	weight[16][21] = weight[21][16] = 61 / (3 * pow(0.7, 3));
	weight[11][12] = weight[12][11] = 61 / (1.3 * 0.6);
	weight[11][17] = weight[17][11] = 104 / (1.3 * 0.6);
	weight[11][18] = weight[18][11] = 104 / (3 * pow(0.9, 3));
	weight[12][17] = weight[17][12] = 128 / (1.3 * 0.6);
	weight[12][18] = weight[18][12] = 73 / (3 * pow(0.9, 3));
	weight[12][13] = weight[13][12] = 132 / (3 * pow(0.8, 3));
	weight[13][18] = weight[18][13] = 150 / (3 * pow(0.9, 3));
	weight[13][19] = weight[19][13] = 33 / (3 * pow(1, 3));
	weight[17][18] = weight[18][17] = 101 / (3 * pow(0.9, 3));
	weight[17][21] = weight[21][17] = 99 / (3 * pow(0.8, 3));
	weight[17][22] = weight[22][17] = 76 / (3 * pow(0.8, 3));
	weight[18][22] = weight[22][18] = 137 / (3 * pow(0.9, 3));
	weight[18][19] = weight[19][18] = 141 / (3 * pow(0.9, 3));
	weight[18][25] = weight[25][18] = 92 / (3 * pow(0.9, 3));
	weight[18][24] = weight[24][18] = 159 / (3 * pow(0.7, 3));
	weight[19][25] = weight[25][19] = 146 / (3 * pow(0.9, 3));
	weight[20][21] = weight[21][20] = 73 / (3 * pow(0.9, 3));
	weight[20][30] = weight[30][20] = 162 / (3 * pow(0.9, 3));
	weight[20][38] = weight[38][20] = 81 / (3 * pow(0.7, 3));
	weight[21][38] = weight[38][21] = 75 / (3 * pow(0.7, 3));
	weight[21][22] = weight[22][21] = 81 / (3 * pow(0.9, 3));
	weight[38][30] = weight[30][38] = 124 / (3 * pow(0.8, 3));
	weight[38][28] = weight[28][38] = 75 / (3 * pow(0.7, 3));
	weight[38][22] = weight[22][38] = 107 / (3 * pow(0.9, 3));
	weight[38][23] = weight[23][38] = 180 / (3 * pow(0.7, 3));
	weight[22][28] = weight[28][22] = 147 / (3 * pow(0.8, 3));
	weight[22][23] = weight[23][22] = 108 / (3 * pow(0.8, 3));
	weight[22][24] = weight[24][22] = 153 / (3 * pow(0.9, 3));
	weight[22][25] = weight[25][22] = 159 / (3 * pow(0.9, 3));
	weight[25][24] = weight[24][25] = 81 / (3 * pow(0.9, 3));
	weight[30][28] = weight[28][30] = 90 / (3 * pow(0.9, 3));
	weight[30][33] = weight[33][30] = 137 / (3 * pow(0.9, 3));
	weight[30][29] = weight[29][30] = 114 / (3 * pow(0.8, 3));
	weight[28][29] = weight[29][28] = 80 / (3 * pow(0.7, 3));
	weight[28][23] = weight[23][28] = 174 / (3 * pow(0.8, 3));
	weight[28][27] = weight[27][28] = 159 / (3 * pow(0.8, 3));
	weight[23][27] = weight[27][23] = 98 / (3 * pow(0.8, 3));
	weight[23][24] = weight[24][23] = 56 / (3 * pow(0.9, 3));
	weight[23][26] = weight[26][23] = 111 / (3 * pow(0.9, 3));
	weight[24][26] = weight[26][24] = 60 / (3 * pow(0.9, 3));
	weight[27][26] = weight[26][27] = 142 / (3 * pow(0.9, 3));
	weight[31][26] = weight[26][31] = 83 / (3 * pow(0.9, 3));
	weight[31][27] = weight[27][31] = 84 / (3 * pow(0.9, 3));
	weight[27][37] = weight[37][27] = 79 / (3 * pow(0.7, 3));
	weight[29][33] = weight[33][29] = 71 / (3 * pow(0.8, 3));
	weight[29][37] = weight[37][29] = 104 / (3 * pow(0.7, 3));
	weight[29][32] = weight[32][29] = 73 / (3 * pow(0.9, 3));
	weight[29][27] = weight[27][29] = 142 / (3 * pow(0.7, 3));
	weight[32][37] = weight[37][32] = 48 / (3 * pow(0.9, 3));
	weight[32][33] = weight[33][32] = 82 / (3 * pow(0.9, 3));
	weight[34][33] = weight[33][34] = 111 / (3 * pow(0.9, 3));
	weight[32][34] = weight[34][32] = 52 / (3 * pow(0.9, 3));
	weight[32][35] = weight[35][32] = 72 / (3 * pow(0.9, 3));
	weight[34][35] = weight[35][34] = 43 / (3 * pow(0.9, 3));
	weight[37][35] = weight[35][37] = 49 / (3 * pow(0.9, 3));
	weight[36][35] = weight[35][36] = 107 / (3 * pow(0.9, 3));
	weight[36][37] = weight[37][36] = 131 / (3 * pow(0.9, 3));

}
int Function::find_node(string name) {
	for (int i = 0; i < building_number; i++)
	{
		if (ve[i].name == name)
		{
			return i;
			break;
		}
	}
	return -1;
}
void Function::Dijkstra(int start, int end, int mode) {
	int dis[building_number];
	int path[building_number];
	//判断模式并初始化
	/*if (mode == 1) this->init1();
	else if (mode == 2) this->init2();
	else this->init3();*/
	cout << setiosflags(ios::fixed) << setprecision(2);
	for (int i = 0; i < building_number; i++) //初始化dis path
	{
		if (start != i && weight[start][i] == 0)
			dis[i] = INF;
		else if (weight[start][i] != 0)
			dis[i] = weight[start][i];
		else if (start == i)
			dis[i] = 0;
		path[i] = -1;
	}
	bool visited[building_number] = { false };
	visited[start] = true;
	while (1)
	{
		int j;
		bool flag = false;
		for (j = 0; j < building_number; j++)
		{
			if (visited[j] == false)
			{
				flag = true;
				break;
			}
		}
		int min = j;
		if (flag == false)
			break;
		for (int i = 0; i < building_number; i++)
		{
			if (visited[i] == false)
				if (dis[min] > dis[i])
					min = i;
		}
		visited[min] = true; //收录的条件就是dis里面最小的
		for (int i = 0; i < building_number; i++)
		{
			if (weight[min][i] != 0 && visited[i] == false) //i是min的邻接点
				if (dis[i] > dis[min] + weight[min][i])
				{
					dis[i] = dis[min] + weight[min][i];
					//暂时的，还不能收入，不确定是不是dist最小的，或者不确定后面有没有更小的
					path[i] = min; //暂时的
				}
		}
	}
	if (dis[end] == INF) {
		cout << "从" << ve[start].name << "->" << ve[end].name << "不通" << endl;
		return;
	}
	if (mode == 1) {
		//输出符合策略的最优解
		cout << "从" << ve[start].name << "->" << ve[end].name << "的距离为：" << dis[end] << "m\n" << "路径为：";
		int n = end;
		stack<int> st;
		st.push(end);
		while (path[n] != -1)
		{
			st.push(path[n]);
			n = path[n];
		}
		st.push(start);
		cout << ve[st.top()].name;
		st.pop();
		while (!st.empty())
		{
			cout << "->" << ve[st.top()].name;
			st.pop();
		}
		cout << endl;
	}
	else if (mode == 2) {
		cout << "从" << ve[start].name << "->" << ve[end].name << "的最短时间为：" << dis[end] / 60.0 << "min\n" << "路径为：";
		int n = end;
		stack<int> st;
		st.push(end);
		while (path[n] != -1)
		{
			st.push(path[n]);
			n = path[n];
		}
		st.push(start);
		cout << ve[st.top()].name;
		st.pop();
		while (!st.empty())
		{
			cout << "->" << ve[st.top()].name;
			st.pop();
		}
		cout << endl;
	}
	else {
		cout << "从" << ve[start].name << "->" << ve[end].name << "的最短时间为：" << dis[end] / 60.0 << "min\n" << "路径为：";
		int n = end;
		stack<int> st;
		st.push(end);
		while (path[n] != -1)
		{
			st.push(path[n]);
			n = path[n];
		}
		st.push(start);
		cout << ve[st.top()].name;
		int tmp = st.top();
		st.pop();
		while (!st.empty())
		{
			if ((tmp == 11 and (st.top() == 12 or st.top() == 17)) or (tmp == 12 and st.top() == 17) or (tmp == 5 and st.top() == 6) or (tmp == 9 and st.top() == 10)) {
				cout << "->(步行)" << ve[st.top()].name;
			}
			else {
				cout << "->(自行车)" << ve[st.top()].name;
			}
			tmp = st.top();
			st.pop();
		}
		cout << endl;
	}
}
void Function::Visiter() {
	string start_name;
	cout << "输入起点：";
	cin >> start_name;
	string end_name;
	cout << "输入终点：";
	cin >> end_name;
	cout << "策略1or2or3：";
	int mode;
	cin >> mode;
	if (mode == 1) this->init1();
	else if (mode == 2) this->init2();
	else this->init3();
	int j = find_node(end_name);
	int i = find_node(start_name);
	while (i == -1 || j == -1)
	{
		cout << "无此信息，请重新输入" << endl;
		cout << "输入起点：";
		cin >> start_name;
		i = find_node(start_name);
		cout << "输入终点：";
		cin >> end_name;
		j = find_node(end_name);
	}
	if ((i <= 38 and j >= 39) or (i >= 39 and j <= 38)) {
		cout << "您所要去的目的点需要跨校区,";
		if (i >= 39) {
			cout << "您可以乘坐校车或者自行选用交通工具前往校本部...前往校外的线路如下" << endl;
			Dijkstra(i, 39, mode);
			cross_bupt(i, j);
			cout << "到达后的路线选择如下： ";
			Dijkstra(30, j, mode);
		}
		else {
			cout << "您可以乘坐校车或者自行选用交通工具前往沙河本部...前往西门的路线如下" << endl;
			Dijkstra(i, 30, mode);
			cross_bupt(i, j);
			cout << "到达后的路线选择如下： ";
			Dijkstra(39, j, mode);
		}
	}
	else Dijkstra(i, j, mode);
}
void Function::cross_bupt(int i, int j) {
	SYSTEMTIME time1;
	GetLocalTime(&time1);
	this->time[0] = time1.wDayOfWeek;
	this->time[1] = time1.wHour;
	this->time[2] = time1.wMinute;
	/*cout << time;*/
	//设定校车60分钟一班，从早上7点钟开始有校车，校车的时长为60分钟，打车为40分钟，地铁为70分钟
	if (time[1] > 21 or time[1] < 6) cout << "校车运营时间在7时-22时，当前距离运营时间较长..." << endl;
	else {
		if (time[2] != 0) {
			cout << "最近的一班校车在" << time[1] + 1 << ":00 " << "您还需等待" << 60 - time[2] << "分钟" << endl;
		}
		else if (time[2] == 0) {
			if (i <= 14)
				cout << "校车现在正在准备出发，请速速前往学活乘坐校车..." << endl;
			else
				cout << "校车现在正在准备出发，请速速前往西门乘坐校车..." << endl;
		}
	}
	if (i <= 14) {
		cout << "您同样可以选择地铁,出校门后左转直走至沙河地铁站，乘坐昌平线至西二旗换乘13号线至大钟寺后出站坐304路公交车到明光桥站，步行至校本部，全程大约70分钟，您需要步行1.0公里" << endl;
	}
	else {
		cout << "您同样可以选择地铁,出校门后至明光桥站,乘坐304路公交车到大钟寺站，乘坐13号线至至西二旗换乘昌平线到沙河地铁站，步行至沙河，全程大约70分钟，您需要步行1.0公里" << endl;
	}
	cout << "土豪请直接打车至本部校区" << endl;
}
void Function::place_by(int i, int j) {
	int sum;
	cout << "输入您想要途径的位置个数： ";
	cin >> sum;
	cout << "输入您想要途径的位置名称： " << endl;
	vector<int> vi,path,viv;
	vector<vector<int> > vvi;
	viv.push_back(i);
	for (int i = 0; i < sum; i++){
		string tmp;
		cin>>tmp;
		vi.push_back(find_node(tmp));
		viv.push_back(find_node(tmp));
	}
	int des[MAXNUM][MAXNUM];
	viv.push_back(j);
	for (int i = 0; i < sum+2; i++) {
		for (int j = 0; j < sum + 2; j++) {
			if (i == j) des[viv[i]][viv[j]] = INF;
			else des[viv[i]][viv[j]] = get_short_path(viv[i], viv[j]);
		}
	}
	perm(vi, vi.begin(), vi.end(), vvi);
	int km = INF;
	for (int k=0;k<vvi.size();k++)
	{
		int tmp1 = 0;
		int flag = 0;
		tmp1 += des[i][vvi[k][flag ]];
		while (vvi[k].size() - flag > 1) {
			/*tmp1 += get_short_path(vvi[k][flag], vvi[k][flag + 1]);*/
			tmp1 += des[vvi[k][flag]][vvi[k][flag + 1]];
			flag++;
		}
		tmp1 += des[vvi[k][flag]][j];
		if (tmp1 < km) { 
			km = tmp1; 
			path = vvi[k];
		}
		else continue;
	}
	cout << "最短距离为" << km << "m" << endl;
	cout << "路径为" << ve[i].name << "->";
	for (int a = 0;a+1< path.size();a++) {
		put_out(path[a], path[a+1]);
		if(a+1== path.size()-1) put_out(path[a + 1], j);
	}
}
int Function::get_short_path(int start,int end){
	int dis[building_number];
	int path[building_number];
	for (int i = 0; i < building_number; i++) //初始化dis path
	{
		if (start != i && weight[start][i] == 0)
			dis[i] = INF;
		else if (weight[start][i] != 0)
			dis[i] = weight[start][i];
		else if (start == i)
			dis[i] = 0;
		path[i] = -1;
	}
	bool visited[building_number] = { false };
	visited[start] = true;
	while (1)
	{
		int j;
		bool flag = false;
		for (j = 0; j < building_number; j++)
		{
			if (visited[j] == false)
			{
				flag = true;
				break;
			}
		}
		int min = j;
		if (flag == false)
			break;
		for (int i = 0; i < building_number; i++)
		{
			if (visited[i] == false)
				if (dis[min] > dis[i])
					min = i;
		}
		visited[min] = true; //收录的条件就是dis里面最小的
		for (int i = 0; i < building_number; i++)
		{
			if (weight[min][i] != 0 && visited[i] == false) //i是min的邻接点
				if (dis[i] > dis[min] + weight[min][i])
				{
					dis[i] = dis[min] + weight[min][i];
					//暂时的，还不能收入，不确定是不是dist最小的，或者不确定后面有没有更小的
					path[i] = min; //暂时的
				}
		}
	}
	if (dis[end] == INF) return - 1;
	else return dis[end];
}
void Function::perm(vector<int>& vi, vector<int>::iterator begin,
	vector<int>::iterator end, vector<vector<int> >& vvi)
{
	if (begin == end)//递归的基础部分
	{
		vector<int> temp;
		for (vector<int>::iterator it = vi.begin(); it != end; it++)
		{
			temp.push_back(*it);
		}
		vvi.push_back(temp);
	}
	else
	{
		for (auto it = begin; it != end; it++)
		{
			swap(*begin, *it);
			perm(vi, begin + 1, end, vvi);
			swap(*begin, *it);
		}
	}
}
void Function::put_out(int start,int end){
	int dis[building_number];
	int path[building_number];
	for (int i = 0; i < building_number; i++) //初始化dis path
	{
		if (start != i && weight[start][i] == 0)
			dis[i] = INF;
		else if (weight[start][i] != 0)
			dis[i] = weight[start][i];
		else if (start == i)
			dis[i] = 0;
		path[i] = -1;
	}
	bool visited[building_number] = { false };
	visited[start] = true;
	while (1)
	{
		int j;
		bool flag = false;
		for (j = 0; j < building_number; j++)
		{
			if (visited[j] == false)
			{
				flag = true;
				break;
			}
		}
		int min = j;
		if (flag == false)
			break;
		for (int i = 0; i < building_number; i++)
		{
			if (visited[i] == false)
				if (dis[min] > dis[i])
					min = i;
		}
		visited[min] = true; //收录的条件就是dis里面最小的
		for (int i = 0; i < building_number; i++)
		{
			if (weight[min][i] != 0 && visited[i] == false) //i是min的邻接点
				if (dis[i] > dis[min] + weight[min][i])
				{
					dis[i] = dis[min] + weight[min][i];
					//暂时的，还不能收入，不确定是不是dist最小的，或者不确定后面有没有更小的
					path[i] = min; //暂时的
				}
		}
	}
	if (dis[end] == INF) {
		cout << "从" << ve[start].name << "->" << ve[end].name << "不通" << endl;
		return;
	}
	else {
		//输出符合策略的最优解
		int n = end;
		stack<int> st;
		st.push(end);
		while (path[n] != -1)
		{
			st.push(path[n]);
			n = path[n];
		}
		st.push(start);
		cout << ve[st.top()].name;
		st.pop();
		while (!st.empty())
		{
			cout << "->" << ve[st.top()].name;
			st.pop();
		}
		cout << endl;
	}
	
}
