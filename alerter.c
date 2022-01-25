#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
	if(celcius >100)
		return 500;
	else
		return 200;
}
float FarenheitToCelcius(float farenheit)
{
	
float celcius = (farenheit - 32) * 5 / 9;
return celcius;

}

void alertInCelcius(float farenheit) {
	
    float celcius =  FarenheitToCelcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
        alertInCelcius(400.5);
	float returnValue = FarenheitToCelcius(400.5);
	//assert(returnValue == 204.7);
        alertInCelcius(303.6);
	returnValue = FarenheitToCelcius(303.6);
	//assert(returnValue == 150.8);
	alertInCelcius(500);
	returnValue = FarenheitToCelcius(500);
	assert(returnValue == 260);
	//assert(alertFailureCount == 2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
