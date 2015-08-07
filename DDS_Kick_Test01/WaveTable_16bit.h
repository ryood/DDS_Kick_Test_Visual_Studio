// table of 16bit (0..65535), 1024 values / one period
uint16_t waveTableSine[] = {
	32767,
	32968,
	33169,
	33370,
	33571,
	33772,
	33973,
	34174,
	34375,
	34576,
	34776,
	34977,
	35178,
	35378,
	35578,
	35779,
	35979,
	36179,
	36379,
	36578,
	36778,
	36978,
	37177,
	37376,
	37575,
	37774,
	37972,
	38171,
	38369,
	38567,
	38765,
	38962,
	39160,
	39357,
	39554,
	39750,
	39946,
	40142,
	40338,
	40534,
	40729,
	40924,
	41118,
	41313,
	41507,
	41700,
	41893,
	42086,
	42279,
	42471,
	42663,
	42854,
	43046,
	43236,
	43427,
	43617,
	43806,
	43995,
	44184,
	44372,
	44560,
	44747,
	44934,
	45121,
	45307,
	45492,
	45677,
	45862,
	46046,
	46229,
	46412,
	46595,
	46777,
	46958,
	47139,
	47320,
	47500,
	47679,
	47858,
	48036,
	48213,
	48391,
	48567,
	48743,
	48918,
	49093,
	49267,
	49440,
	49613,
	49785,
	49956,
	50127,
	50298,
	50467,
	50636,
	50804,
	50972,
	51138,
	51305,
	51470,
	51635,
	51799,
	51962,
	52125,
	52287,
	52448,
	52608,
	52768,
	52927,
	53085,
	53242,
	53399,
	53554,
	53710,
	53864,
	54017,
	54170,
	54322,
	54473,
	54623,
	54772,
	54921,
	55069,
	55215,
	55362,
	55507,
	55651,
	55795,
	55937,
	56079,
	56220,
	56360,
	56499,
	56637,
	56774,
	56911,
	57046,
	57181,
	57314,
	57447,
	57579,
	57710,
	57840,
	57969,
	58097,
	58224,
	58350,
	58475,
	58599,
	58722,
	58845,
	58966,
	59086,
	59205,
	59324,
	59441,
	59557,
	59672,
	59787,
	59900,
	60012,
	60123,
	60234,
	60343,
	60451,
	60558,
	60664,
	60769,
	60873,
	60975,
	61077,
	61178,
	61278,
	61376,
	61474,
	61570,
	61665,
	61760,
	61853,
	61945,
	62036,
	62126,
	62214,
	62302,
	62388,
	62474,
	62558,
	62641,
	62723,
	62804,
	62884,
	62963,
	63040,
	63117,
	63192,
	63266,
	63339,
	63411,
	63481,
	63551,
	63619,
	63686,
	63752,
	63817,
	63881,
	63943,
	64004,
	64065,
	64124,
	64181,
	64238,
	64293,
	64348,
	64401,
	64452,
	64503,
	64552,
	64601,
	64648,
	64694,
	64738,
	64782,
	64824,
	64865,
	64905,
	64944,
	64981,
	65017,
	65052,
	65086,
	65118,
	65150,
	65180,
	65209,
	65236,
	65263,
	65288,
	65312,
	65335,
	65356,
	65377,
	65396,
	65414,
	65430,
	65446,
	65460,
	65473,
	65485,
	65495,
	65504,
	65512,
	65519,
	65525,
	65529,
	65532,
	65534,
	65535,
	65534,
	65532,
	65529,
	65525,
	65519,
	65512,
	65504,
	65495,
	65485,
	65473,
	65460,
	65446,
	65430,
	65414,
	65396,
	65377,
	65356,
	65335,
	65312,
	65288,
	65263,
	65236,
	65209,
	65180,
	65150,
	65118,
	65086,
	65052,
	65017,
	64981,
	64944,
	64905,
	64865,
	64824,
	64782,
	64738,
	64694,
	64648,
	64601,
	64552,
	64503,
	64452,
	64401,
	64348,
	64293,
	64238,
	64181,
	64124,
	64065,
	64004,
	63943,
	63881,
	63817,
	63752,
	63686,
	63619,
	63551,
	63481,
	63411,
	63339,
	63266,
	63192,
	63117,
	63040,
	62963,
	62884,
	62804,
	62723,
	62641,
	62558,
	62474,
	62388,
	62302,
	62214,
	62126,
	62036,
	61945,
	61853,
	61760,
	61665,
	61570,
	61474,
	61376,
	61278,
	61178,
	61077,
	60975,
	60873,
	60769,
	60664,
	60558,
	60451,
	60343,
	60234,
	60123,
	60012,
	59900,
	59787,
	59672,
	59557,
	59441,
	59324,
	59205,
	59086,
	58966,
	58845,
	58722,
	58599,
	58475,
	58350,
	58224,
	58097,
	57969,
	57840,
	57710,
	57579,
	57447,
	57314,
	57181,
	57046,
	56911,
	56774,
	56637,
	56499,
	56360,
	56220,
	56079,
	55937,
	55795,
	55651,
	55507,
	55362,
	55215,
	55069,
	54921,
	54772,
	54623,
	54473,
	54322,
	54170,
	54017,
	53864,
	53710,
	53554,
	53399,
	53242,
	53085,
	52927,
	52768,
	52608,
	52448,
	52287,
	52125,
	51962,
	51799,
	51635,
	51470,
	51305,
	51138,
	50972,
	50804,
	50636,
	50467,
	50298,
	50127,
	49956,
	49785,
	49613,
	49440,
	49267,
	49093,
	48918,
	48743,
	48567,
	48391,
	48213,
	48036,
	47858,
	47679,
	47500,
	47320,
	47139,
	46958,
	46777,
	46595,
	46412,
	46229,
	46046,
	45862,
	45677,
	45492,
	45307,
	45121,
	44934,
	44747,
	44560,
	44372,
	44184,
	43995,
	43806,
	43617,
	43427,
	43236,
	43046,
	42854,
	42663,
	42471,
	42279,
	42086,
	41893,
	41700,
	41507,
	41313,
	41118,
	40924,
	40729,
	40534,
	40338,
	40142,
	39946,
	39750,
	39554,
	39357,
	39160,
	38962,
	38765,
	38567,
	38369,
	38171,
	37972,
	37774,
	37575,
	37376,
	37177,
	36978,
	36778,
	36578,
	36379,
	36179,
	35979,
	35779,
	35578,
	35378,
	35178,
	34977,
	34776,
	34576,
	34375,
	34174,
	33973,
	33772,
	33571,
	33370,
	33169,
	32968,
	32767,
	32566,
	32365,
	32164,
	31963,
	31762,
	31561,
	31360,
	31159,
	30958,
	30758,
	30557,
	30356,
	30156,
	29956,
	29755,
	29555,
	29355,
	29155,
	28956,
	28756,
	28556,
	28357,
	28158,
	27959,
	27760,
	27562,
	27363,
	27165,
	26967,
	26769,
	26572,
	26374,
	26177,
	25980,
	25784,
	25588,
	25392,
	25196,
	25000,
	24805,
	24610,
	24416,
	24221,
	24027,
	23834,
	23641,
	23448,
	23255,
	23063,
	22871,
	22680,
	22488,
	22298,
	22107,
	21917,
	21728,
	21539,
	21350,
	21162,
	20974,
	20787,
	20600,
	20413,
	20227,
	20042,
	19857,
	19672,
	19488,
	19305,
	19122,
	18939,
	18757,
	18576,
	18395,
	18214,
	18034,
	17855,
	17676,
	17498,
	17321,
	17143,
	16967,
	16791,
	16616,
	16441,
	16267,
	16094,
	15921,
	15749,
	15578,
	15407,
	15236,
	15067,
	14898,
	14730,
	14562,
	14396,
	14229,
	14064,
	13899,
	13735,
	13572,
	13409,
	13247,
	13086,
	12926,
	12766,
	12607,
	12449,
	12292,
	12135,
	11980,
	11824,
	11670,
	11517,
	11364,
	11212,
	11061,
	10911,
	10762,
	10613,
	10465,
	10319,
	10172,
	10027,
	9883,
	9739,
	9597,
	9455,
	9314,
	9174,
	9035,
	8897,
	8760,
	8623,
	8488,
	8353,
	8220,
	8087,
	7955,
	7824,
	7694,
	7565,
	7437,
	7310,
	7184,
	7059,
	6935,
	6812,
	6689,
	6568,
	6448,
	6329,
	6210,
	6093,
	5977,
	5862,
	5747,
	5634,
	5522,
	5411,
	5300,
	5191,
	5083,
	4976,
	4870,
	4765,
	4661,
	4559,
	4457,
	4356,
	4256,
	4158,
	4060,
	3964,
	3869,
	3774,
	3681,
	3589,
	3498,
	3408,
	3320,
	3232,
	3146,
	3060,
	2976,
	2893,
	2811,
	2730,
	2650,
	2571,
	2494,
	2417,
	2342,
	2268,
	2195,
	2123,
	2053,
	1983,
	1915,
	1848,
	1782,
	1717,
	1653,
	1591,
	1530,
	1469,
	1410,
	1353,
	1296,
	1241,
	1186,
	1133,
	1082,
	1031,
	982,
	933,
	886,
	840,
	796,
	752,
	710,
	669,
	629,
	590,
	553,
	517,
	482,
	448,
	416,
	384,
	354,
	325,
	298,
	271,
	246,
	222,
	199,
	178,
	157,
	138,
	120,
	104,
	88,
	74,
	61,
	49,
	39,
	30,
	22,
	15,
	9,
	5,
	2,
	0,
	0,
	0,
	2,
	5,
	9,
	15,
	22,
	30,
	39,
	49,
	61,
	74,
	88,
	104,
	120,
	138,
	157,
	178,
	199,
	222,
	246,
	271,
	298,
	325,
	354,
	384,
	416,
	448,
	482,
	517,
	553,
	590,
	629,
	669,
	710,
	752,
	796,
	840,
	886,
	933,
	982,
	1031,
	1082,
	1133,
	1186,
	1241,
	1296,
	1353,
	1410,
	1469,
	1530,
	1591,
	1653,
	1717,
	1782,
	1848,
	1915,
	1983,
	2053,
	2123,
	2195,
	2268,
	2342,
	2417,
	2494,
	2571,
	2650,
	2730,
	2811,
	2893,
	2976,
	3060,
	3146,
	3232,
	3320,
	3408,
	3498,
	3589,
	3681,
	3774,
	3869,
	3964,
	4060,
	4158,
	4256,
	4356,
	4457,
	4559,
	4661,
	4765,
	4870,
	4976,
	5083,
	5191,
	5300,
	5411,
	5522,
	5634,
	5747,
	5862,
	5977,
	6093,
	6210,
	6329,
	6448,
	6568,
	6689,
	6812,
	6935,
	7059,
	7184,
	7310,
	7437,
	7565,
	7694,
	7824,
	7955,
	8087,
	8220,
	8353,
	8488,
	8623,
	8760,
	8897,
	9035,
	9174,
	9314,
	9455,
	9597,
	9739,
	9883,
	10027,
	10172,
	10319,
	10465,
	10613,
	10762,
	10911,
	11061,
	11212,
	11364,
	11517,
	11670,
	11824,
	11980,
	12135,
	12292,
	12449,
	12607,
	12766,
	12926,
	13086,
	13247,
	13409,
	13572,
	13735,
	13899,
	14064,
	14229,
	14396,
	14562,
	14730,
	14898,
	15067,
	15236,
	15407,
	15578,
	15749,
	15921,
	16094,
	16267,
	16441,
	16616,
	16791,
	16967,
	17143,
	17321,
	17498,
	17676,
	17855,
	18034,
	18214,
	18395,
	18576,
	18757,
	18939,
	19122,
	19305,
	19488,
	19672,
	19857,
	20042,
	20227,
	20413,
	20600,
	20787,
	20974,
	21162,
	21350,
	21539,
	21728,
	21917,
	22107,
	22298,
	22488,
	22680,
	22871,
	23063,
	23255,
	23448,
	23641,
	23834,
	24027,
	24221,
	24416,
	24610,
	24805,
	25000,
	25196,
	25392,
	25588,
	25784,
	25980,
	26177,
	26374,
	26572,
	26769,
	26967,
	27165,
	27363,
	27562,
	27760,
	27959,
	28158,
	28357,
	28556,
	28756,
	28956,
	29155,
	29355,
	29555,
	29755,
	29956,
	30156,
	30356,
	30557,
	30758,
	30958,
	31159,
	31360,
	31561,
	31762,
	31963,
	32164,
	32365,
	32566
};
