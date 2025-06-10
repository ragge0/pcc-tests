
#include <stdio.h>

enum { ISG, ISGE, ISL, ISLE, ISLG, ISUN, /* ISEQS */};

char *tname[] = { "isgreater", "isgreaterequal", "isless", 
	"islessequal", "islessgreater", "isunordered", "iseqsig" };

int
testingf(int t, float f, float g)
{
	switch (t) {
	case ISG: t = __builtin_isgreater(f, g); break;
	case ISGE: t = __builtin_isgreaterequal(f, g); break;
	case ISL: t = __builtin_isless(f, g); break;
	case ISLE: t = __builtin_islessequal(f, g); break;
	case ISLG: t = __builtin_islessgreater(f, g); break;
	case ISUN: t = __builtin_isunordered(f, g); break;
//	case ISEQS: t = __builtin_iseqsig(f, g); break;
	}
	return t;
}

int
testing(int t, double f, double g)
{
	switch (t) {
	case ISG: t = __builtin_isgreater(f, g); break;
	case ISGE: t = __builtin_isgreaterequal(f, g); break;
	case ISL: t = __builtin_isless(f, g); break;
	case ISLE: t = __builtin_islessequal(f, g); break;
	case ISLG: t = __builtin_islessgreater(f, g); break;
	case ISUN: t = __builtin_isunordered(f, g); break;
//	case ISEQS: t = __builtin_iseqsig(f, g); break;
	}
	return t;
}

int
testingl(int t, long double f, long double g)
{
	switch (t) {
	case ISG: t = __builtin_isgreater(f, g); break;
	case ISGE: t = __builtin_isgreaterequal(f, g); break;
	case ISL: t = __builtin_isless(f, g); break;
	case ISLE: t = __builtin_islessequal(f, g); break;
	case ISLG: t = __builtin_islessgreater(f, g); break;
	case ISUN: t = __builtin_isunordered(f, g); break;
//	case ISEQS: t = __builtin_iseqsig(f, g); break;
	}
	return t;
}

/* ISG, ISGE, ISL, ISLE, ISLG, ISUN */
struct tary {
	double f, g;
	int res[7];
} tary[] = {
	{ 0.0, 0.0, { 0, 1, 0, 1, 0, 0, 0 }, },
	{ 0.0, 1.0, { 0, 0, 1, 1, 1, 0, 0 }, },
	{ 1.0, 0.0, { 1, 1, 0, 0, 1, 0, 0 }, },
	{ __builtin_nan(""), 0.0, { 0, 0, 0, 0, 0, 1, 0 }, },
	{ 0.0, __builtin_nan(""), { 0, 0, 0, 0, 0, 1, 0 }, },
	{ __builtin_nan(""), __builtin_nan(""), { 0, 0, 0, 0, 0, 1, 0 }, },
};

int
main()
{
	int i, j, r, q;

	q = 0;
	for (i = 0; i < ISUN+1; i++) {
		for (j = 0; j < sizeof(tary)/sizeof(tary[0]); j++) {
			struct tary *tp = &tary[j];
			if ((r = testingf(i, tp->f, tp->g)) != tp->res[i]) {
				printf("testf %s idx %d failed: %d != %d\n", 
				   tname[i], tp - tary, r, tp->res[i]);
				q = 1;
			} else
				printf("testf %s idx %d OK: %d == %d\n",
				    tname[i], tp - tary, r, tp->res[i]);
			if ((r = testing(i, tp->f, tp->g)) != tp->res[i]) {
				printf("testd %s idx %d failed: %d != %d\n", 
				   tname[i], tp - tary, r, tp->res[i]);
				q = 1;
			} else
				printf("testd %s idx %d OK: %d == %d\n",
				    tname[i], tp - tary, r, tp->res[i]);
			if ((r = testing(i, tp->f, tp->g)) != tp->res[i]) {
				printf("testl %s idx %d failed: %d != %d\n", 
				   tname[i], tp - tary, r, tp->res[i]);
				q = 1;
			} else
				printf("testl %s idx %d OK: %d == %d\n",
				    tname[i], tp - tary, r, tp->res[i]);
		}
	}
	return q;
}
