namespace mlm {

float	radians(const float &degrees)
{
	return (degrees * (float)0.0174532925199);
}

double	radians(const double &degrees)
{
	return (degrees * (double)0.0174532925199);
}

float	degrees(const float &radians)
{
	return (radians * (float)57.2957795130);
}

double	degrees(const double &radians)
{
	return (radians * (double)57.2957795130);
}

}
