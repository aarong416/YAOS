/* Converts float to a string. Safe to use in signal handling */
void ftoa(float n, char* result)
{
	//char result[10];
	int i;
	int count = 0;
	float temp = n;
	int res = 0;

	while (temp >= 1){ // Count number of whole digits
		temp /= 10;
		++count;
		temp -= (int)temp;
	}

	// Write whole digits into the string
	for (i = 0; i < count; i++) {
		temp *= 10;
		res = (int)temp;
		result[i] = res + '0';
	}

	if (count == 0) {    // If float is smaller than 1, add "0" at the beginning
		result[0] = '0';
		++i;
		++count;
	}
	result[i] = '.';
	++count;

	// Write all 4 decimal cases into the string
	for (i = 0; i < 4; i++) {
		n -= (int)n;
		n *= 10;
		res = (int)n;
		result[i + count] = res + '0';
	}

    result[i+count] = '\0';
}
