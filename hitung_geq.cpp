void hitung_geq(int freq, float boost, float qual)
{
	float gain_linier, omega, sn, cs, alpha, Ax;
	if(boost == 0)
	{
		B0 = 1.0;
		B1 = B2 = A1 = A2 = 0;
	}
	else
	{
		omega = 2 * 3.14159265359 * freq / 48000;
		Ax    = pow(10,boost/40);
		sn    = sin(omega);
		cs    = cos(omega);
		alpha = sn / (2 * qual);
		
		A0 = 1 + (alpha / Ax);
		A1 = -1 * (2 * cs) / A0;
		A2 = (1 - (alpha / Ax)) / A0;
		
		gain_linier = 1 / A0;
		
		B0 = (1 + (alpha * Ax)) * gain_linier;
		B1 = -1 * (2 * cs) * gain_linier;
		B2 = (1 - (alpha * Ax)) * gain_linier;
		
		// invert nilai A1 dan A2
		A1 *= -1;
		A2 *= -1;
	}
}
