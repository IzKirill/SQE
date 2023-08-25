void MyAssertNumbers(const double lhn, const double rhn, const char sign[], const int nline, const char file[])
{
    char sequals[] = "==";
    char smore[] = ">";
    char sless[] = "<";
    char sno_equals[] = "!=";
    char smore_equal[] = ">=";
    char sless_equal[] = "<=";

    if (strcmp(sign, sequals) == 0)
    {
        if (cmp_doubles(lhn, rhn) == 1)
        {
            printf("ERROR: %lf == %lf, LINE: %d, FILE: %s", lhn, rhn, nline, file);
            exit(5);
        }

    }

    if (strcmp(sign, smore) == 0)
    {
        if (lhn <= rhn)
        {
            printf("ERROR: %lf > %lf, LINE: %d, FILE: %s", lhn, rhn, nline, file);
            exit(5);
        }
    }

    if (strcmp(sign, sless) == 0)
    {
        if (lhn >= rhn)
        {
            printf("ERROR: %lf < %lf, LINE: %d, FILE: %s", lhn, rhn, nline, file);
            exit(5);
        }
    }

    if (strcmp(sign, sno_equals) == 0)
    {
        if (cmp_doubles(lhn, rhn) == 0)
        {
            printf("ERROR: %lf != %lf, LINE: %d, FILE: %s", lhn, rhn, nline, file);
            exit(5);
        }
    }

    if (strcmp(sign, smore_equal) == 0)
    {
        if (lhn < rhn)
        {
            printf("ERROR: %lf >= %lf, LINE: %d, FILE: %s", lhn, rhn, nline, file);
            exit(5);
        }
    }

    if (strcmp(sign, sless_equal) == 0)
    {
        if (lhn > rhn)
        {
            printf("ERROR: %lf <= %lf, LINE: %d, FILE: %s", lhn, rhn, nline, file);
            exit(5);
        }
    }
}
