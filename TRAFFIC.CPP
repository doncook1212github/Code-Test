/***********************************************************************/
/* Simulates 4-way intersection. Each way has 4 lanes: left turn lane, */
/* two through lanes, and a right turn lane. Each way has 2 lights,    */
/* one for the left turn lane and one for the pair of through lanes.   */
/***********************************************************************/

#include<iostream.h>     /* Needed for cout, cin, endl        */

/**************************************************************/
/* Establish parameters for how long a given traffic light    */
/* will remain GREEN, YELLOW.                                 */
/**************************************************************/

#define NUM_CYCLES 4	 /* Specify number of full light      */
			 /* cycles to display output for.     */

#define NS_LT_G_DELAY 20 /* North-South left turn GREEN time  */
#define NS_LT_Y_DELAY 5  /* North-South left turn YELLOW time */
#define EW_LT_G_DELAY 20 /* East-West left turn GREEN time    */
#define EW_LT_Y_DELAY 5  /* East-West left turn YELLOW time   */
#define NS_TH_G_DELAY 40 /* North-South through GREEN time    */
#define NS_TH_Y_DELAY 5  /* North-South through YELLOW time   */
#define EW_TH_G_DELAY 40 /* East-West through GREEN time      */
#define EW_TH_Y_DELAY 5  /* East-West through YELLOW time     */

enum Color /* Define possible colors for a left turn light    */
{
  GREEN,
  YELLOW,
  RED,
  ORANGE   /* Orange not used in current implementation       */
};

class LightNoTurn   /* Light for straight through lanes.               */
{		    /* May be GREEN, YELLOW, or RED.                   */
		    /* Must code to check for valid colors.            */
		    /* Has only 1 data member (current_color).         */
		    /* Has methods set_color, inc_color, and get_color.*/
  public:
    void set_color(Color nextColor);
    void inc_color();
    Color get_color();
    LightNoTurn();

  private:
    Color current_color;
};

class LightLeftTurn /* Light for left turn lanes. May be GREEN,        */
		    /* YELLOW, RED, or ORANGE.
		    /* Has only 1 data member (current_color).         */
		    /* Has methods set_color, inc_color, and get_color.*/
{
  public:
    void set_color(Color nextColor);
    void inc_color();
    Color get_color();
    LightLeftTurn();

  private:
    Color current_color;
};

void LightNoTurn::set_color(Color desired_color)
			    /* Set color of light.                     */
{
  if ((desired_color > RED)||(desired_color < GREEN))
    current_color = RED;    /* Prevent ORANGE and other invalid colors */
  else
  current_color = desired_color;
}

void LightNoTurn::inc_color()
			    /* Change to next color (RED to GREEN,     */
			    /* GREEN to YELLOW, or YELLOW to RED.      */
{
  if (current_color < RED)
    current_color++;
  else
    current_color = GREEN;  /* Avoid invalid colors and roll back to */
			    /* GREEN after RED.                      */
}

Color LightNoTurn::get_color()  /* Returns current_color of object.  */
{
  return current_color;
}

LightNoTurn::LightNoTurn()
{                         /* Default constructor.                */
			  /* Ensure that initial value of        */
			  /* current_color is RED.               */
  current_color = RED;
}

void LightLeftTurn::set_color(Color desired_color)
			  /* Set color of light.                 */
{
  if ((desired_color > ORANGE )||(desired_color < GREEN))
    current_color = RED;  /* Prevent invalid colors  */
  else
    current_color = desired_color;
}

void LightLeftTurn::inc_color() /* Advance from GREEN to YELLOW,  */
				/* from YELLOW to RED, or from    */
				/* RED to GREEN.                  */
{
  if (current_color < RED)
    current_color++;
  else
    current_color = GREEN; /* Avoid invalid colors. Roll back to   */
			   /* GREEN after RED.                     */
}

Color LightLeftTurn::get_color() /* Report value of 'current_color' */
{
  return current_color;
}

LightLeftTurn::LightLeftTurn() /* Ensure that initial value of       */
			       /* current_color is RED.              */
{
  current_color = RED;
}

void output_lights(int, LightLeftTurn, LightLeftTurn, LightNoTurn, LightNoTurn,
			LightLeftTurn, LightLeftTurn, LightNoTurn, LightNoTurn);

void main()
{
  char c = 'c';	      /* Character variable to accept input and      */
		      /* show console output at program end.         */

  int time = 0;       /* Declare counter that will track time for    */
		      /* determining when lights should change color */

  LightLeftTurn nblt, sblt, eblt, wblt;
		      /* Instantiate LightLeftTurn objects for       */
		      /* northbound (nblt), southbound (sblt),       */
		      /* eastbound (eblt), and westbound (wblt).     */

  LightNoTurn nbth, sbth, ebth, wbth;
		      /* Instantiate LightNoTurn objects for         */
		      /* through-traffic in northbound (nbth),       */
		      /* southbound (sbth), eastbound (ebth),        */
		      /* and westbound (wbth) lanes.                 */

  int nsltG = 0;      /* Time when north-south left turn lights      */
		      /* should turn green. Assumes that north-      */
		      /* south left turn lights are the first to     */
		      /* turn green.                                 */

  int nsltY = NS_LT_G_DELAY; /* Time when north-south left turn      */
			     /* light should turn YELLOW             */


  int nsltR = NS_LT_G_DELAY + NS_LT_Y_DELAY;
			     /* Time when north-south left turn      */
			     /* light should turn RED.               */

  int nsthG = nsltR;
			     /* Time when north-south through lane   */
			     /* light should turn GREEN.             */

  int nsthY = nsltR + NS_TH_G_DELAY;
			    /* Time when north-south through lane    */
			    /* light should turn YELLOW.             */

  int nsthR = nsthY + NS_TH_Y_DELAY;
			    /* Time when north-south through lane    */
			    /* should turn RED.                      */

  int ewltG = nsthR;
			    /* Time when east-west left turn lights  */
			    /* should turn GREEN.                    */

  int ewltY = ewltG + EW_LT_G_DELAY;
			    /* Time when east-west left turn lights  */
			    /* should gurn YELLOW.                   */

  int ewltR = ewltY + EW_LT_Y_DELAY;
			    /* Time when east-west left turn lights  */
			    /* should turn RED.                      */

  int ewthG = ewltR;
			   /* Time when east-west through lane       */
			   /* lights should turn GREEN               */

  int ewthY = ewthG + EW_TH_G_DELAY;
			   /* Time when east-west through lane       */
			   /* lights should turn YELLOW.             */

  int ewthR = ewthY + EW_TH_Y_DELAY;
			   /* Time when east-west through lane       */
			   /* lights should turn RED.                */

  int clock_reset_time = ewthR;
			   /* Time when clock should start over.     */

  for (int i = 0; i < NUM_CYCLES; i++)
  {
    cout << "Current cycle: " << i << endl;
    time = 0;                   /* Start new light cycle.              */
    while (time < clock_reset_time - 1 )
    {
      if (time == nsltG)
      {
	ebth.set_color(RED);    /* Set eastbound and westbound through */
	wbth.set_color(RED);    /* lane lights to RED.                 */

	nblt.set_color(GREEN);  /* Set northbound and southbound       */
	sblt.set_color(GREEN);  /* left turn lanes GREEN.              */
      }
      else if (time == nsltY)
      {
	nblt.set_color(YELLOW); /* Set northbound and southbound       */
	sblt.set_color(YELLOW); /* left turn lanes YELLOW.             */
      }
      else if (time == nsltR)
      {
	nblt.set_color(RED);    /* Set northbound and southbound       */
	sblt.set_color(RED);    /* left turn lanes RED.                */

	nbth.set_color(GREEN);  /* Set northbound and southbound       */
	sbth.set_color(GREEN);  /* through lane lights GREEN.          */
      }
      else if (time == nsthY)
      {
	nbth.set_color(YELLOW); /* Set northbound and southbound       */
	sbth.set_color(YELLOW); /* through lane lights YELLOW.         */
      }
      else if (time == nsthR)
      {
	nbth.set_color(RED);    /* Set northbound and southbound       */
	sbth.set_color(RED);    /* through lane lights RED.            */

	eblt.set_color(GREEN);  /* Set eastbound and westbound         */
	wblt.set_color(GREEN);  /* left turn lane lights GREEN.        */
      }
      else if (time == ewltY)
      {
	eblt.set_color(YELLOW);  /* Set eastbound and westbound         */
	wblt.set_color(YELLOW);  /* left turn lane lights YELLOW.       */
      }
      else if (time == ewltR)
      {
	eblt.set_color(RED);     /* Set eastbound and westbound         */
	wblt.set_color(RED);     /* left turn lane lights RED.          */

	ebth.set_color(GREEN);   /* Set eastbound and westbound through */
	wbth.set_color(GREEN);   /* lane lights GREEN.                  */
      }
      else if (time == ewthY)
      {
	ebth.set_color(YELLOW);  /* Set eastbound and westbound through */
	wbth.set_color(YELLOW);  /* lane lights YELLOW.                 */
      }
      output_lights(time, nblt, sblt, nbth, sbth, eblt, wblt, ebth, wbth);
      time++;                    /* Increment time.                     */
    }
    output_lights(time, nblt, sblt, nbth, sbth, eblt, wblt, ebth, wbth);
  }
//cout << "Press any key followed by <ENTER> to continue.\n";
//cin >> c;
}

void output_lights(int time, LightLeftTurn nblt, LightLeftTurn sblt,
			     LightNoTurn nbth, LightNoTurn sbth,
			     LightLeftTurn eblt, LightLeftTurn wblt,
			     LightNoTurn ebth, LightNoTurn wbth)

/**************************************************************************/
/* Inputs: integer, 2 LightLeftTurn objects followed by 2 LightNoTurn     */
/* objects followed by 2 more LightLeftTurnObjects followd by 2 more      */
/* LightNoTurnObjects.                                                    */
/* Outputs: integer representing time, and a digit (0-2) for each         */
/* object where 0 represents GREEN, 1 represents YELLOW, and 2 represents */
/* RED.                                                                   */
/**************************************************************************/


{
  cout << "Time: " << time << " NBLT: " << nblt.get_color()
       << " SBLT: " << sblt.get_color() << " NBTH: " << nbth.get_color()
       << " SBTH: " << sbth.get_color() << " EBLT: " << eblt.get_color()
       << " WBLT: " << wblt.get_color() << " EBTH: " << ebth.get_color()
       << " WBTH: " << wbth.get_color() << endl;
}