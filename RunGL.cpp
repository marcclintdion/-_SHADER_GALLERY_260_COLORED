#define var GLfloat
//####################################################################################################################


#ifdef WIN32
        #define   glGenerateMipmap       glGenerateMipmapEXT        
        #define   glGenFramebuffers      glGenFramebuffersEXT    
        #define   glBindFramebuffer      glBindFramebufferEXT          
        #define   glFramebufferTexture2D glFramebufferTexture2DEXT            
         
        #define   STRICT
        #define   WIN32_LEAN_AND_MEAN
        #include <windows.h>
        #include <iostream.h>
        #include <fstream.h>
        //using namespace std; //___used for string object

       //-----------------------------------------------------------------------------


        #include <GL/gl.h>
        #include <GL/glu.h>        
        #include "headerFiles/glext.h" 
        #include "headerFiles/glext_Init_A.cpp" 

 
        void InitGL(void);   
        void RenderGL(void); 
        
        
  
        
        
        void ProcessKeyboard(void);
                
        int screenWidth;
        int screenHeight; 
        var viewWidth;
        var viewHeight;          
        
        var keys[256], keypressed[256];        
        #include "cpp/WGL_ARB_multisample.h"



      
        //-------------------------------


#include "headerFiles/VSync.h"   
        
        #include <windows.h>

        void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
        #include "headerFiles/glaux.h"        
        #include "headerFiles/FreeImage.h"
        #include "cpp/freeImage.cpp"
        //------------------------------------------
 
    
#endif
       

var eyePosition[3];

var look_LEFT_RIGHT;
var look_UP_DOWN;       



        GLfloat rotateModel[]   = {0.0, 0.0, 0.0, 0.0};

var moveSet[]          = {0.0, 0.0, -10.0, 0.0};

//####################################################################################################################


#include <math.h>
  

//####################################################################################################################

#include "MATRIX_MATH.cpp"

//####################################################################################################################
#ifdef WIN32
        #include "cubeMaps/cubeMap_GLOBALS.cpp"
#endif

//-------------------------------------------------------------------------------------------------------------------- 

int TEXTURE_WIDTH  = 1024;
int TEXTURE_HEIGHT = 1024;
//------------------------------------




//--------------------------------------------------------------------------------------------------------------
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//----------------------------------------------------------------------------------------

        extern GLuint msaaFramebuffer;

        void RenderGL(void);
        void InitGL  (void);
        void shutDownGL(void);
      
    
        #ifdef __APPLE__
               var viewWidth;
               var viewHeight;
               GLuint  viewFramebuffer;        
        #endif 
          
        //-------------------------------------------------------------------------------

 
GLuint m_uiShadowMapTexture;
GLuint m_uiFrameBufferObject;




//#########################################################################################################|_FREE_IMAGE

void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{

        #ifdef __APPLE__
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        #endif
        
        #ifdef WIN32
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);	        
        glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
        #endif 
}

//===============================================================================================================================                                                   

var     modelView[16];
var     projection[16];
var     mvpMatrix[16];
var     lightProjection[16];
var     mvpMatrixInverse[16];
var     lightMatrix1[16]; 
var     lightMatrix2[16]; 
var     moveSetMatrix[16]; 
var     textureMatrix[16];
var     ProjectionShadow[16];
var     LightModelViewMatrix[16];


GLuint      UNIFORM_MODELVIEWPROJ;
GLuint      UNIFORM_MODELVIEWPROJ_INVERSE;
GLuint      UNIFORM_LIGHT_MATRIX;

//===============================================================================================================================
                               

//######################################################################################################################
                                
                                var changeSet            = 5;
                                var groupSelection       = 0.0;                           
                                
                                var select_POSITION[]    = {  0.0, 0.0, 0.0, 0.0};
                                
                                var spinModel            =    0.0;
                                //---------------------------------------------------- 
                                #include  "_SHADERS/SHADOWS/shadows_24B_GLOBALS.cpp"                              
                                var       adjustShadowMove[]                                        =  {  0.11, 0.0, 0.0, 1.0}; 
                                //=========================================================================================== 
                                var       shadows_POSITION[]                                        =  {  0.0, 0.0, 0.0, 1.0}; 
                                var       shadows_ROTATE[]                                          =  {  1.0, 0.0, 0.0, 0.0};
                                //-------------------------
                                var       moveShadow_A[]                                            =  { -5.93004, -7.35991, -12.7902,   1.0};
                                var       rotateShadow_A[]                                          =  {  0, 1,     0.66,     30.0};
                                var       adjustModelShadow_A_ROTATION                              =    33;
                                //-------------------------
                                var       moveShadow_B[]                                            =  {  0.71,    -0.27,      0.0,      1.0};
                                var       rotateShadow_02[]                                         =  {  0.12,    -4.7,       2.42,   -32.456};
                                var       adjustModelShadow_02_ROTATION                             =    25.0;
                                //-------------------------
                                var       moveShadow_03[]                                           =  { -0.515,  -12.6952,   -0.4400,   1.0};
                                var       rotateShadow_03[]                                         =  {  0.0,      1.0,       1.0,     29.28};                           
                                var       darkness_shadow[]                                         =  {  0.0,      0.0,       0.0,      1.0};                                                      
                                //################################################################################################################
                                
                                //------------------------------------------------
                                var SET_01_POSITION[] = { -5.0,  1.5, 0.0, 0.0};                                                                                                                                                                                                
                                var SET_02_POSITION[] = { -2.5,  1.5, 0.0, 0.0};                                   
                                var SET_03_POSITION[] = {  0.0,  1.5, 0.0, 0.0};                                 
                                var SET_04_POSITION[] = {  2.5,  1.5, 0.0, 0.0};                                                                                                                                                                                                
                                var SET_05_POSITION[] = {  5.0,  1.5, 0.0, 0.0};                                   
                                var SET_06_POSITION[] = { -5.0, -1.75, 0.0, 0.0};                                 
                                var SET_07_POSITION[] = { -2.5, -1.75, 0.0, 0.0};                                  
                                var SET_08_POSITION[] = {  0.0, -1.75, 0.0, 0.0};                                 
                                var SET_09_POSITION[] = {  2.5, -1.75, 0.0, 0.0};                                 
                                var SET_10_POSITION[] = {  5.0, -1.75, 0.0, 0.0};                                   
                                
                                //######################################################################################################
                                //######################################################################################################
                                
                                //===========================================================================================
                                
                                #include "_SHADERS/fresnel/firstCopper/firstCopper_GLOBALS.cpp"                                 
                                //---------------------------------------------------------------------------------  
                                #include "_SHADERS/fresnel/copper/copper_GLOBALS.cpp"                                 
                                //--------------------------------------------------------------------------------- 
                                #include "_SHADERS/electron/blue/blueElectron_GLOBALS.cpp"                                
                                //---------------------------------------------------------------------------------  
                                #include "_SHADERS/fresnel/carbonFiber/carbonFiber_GLOBALS.cpp"                                 
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/electron/grey/greyElectron_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                   
                                #include "_SHADERS/fresnel/bronze/bronze_GLOBALS.cpp"                                 
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/electron/brightOrange/brightOrange_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/squishy/squishy_01/squishy_01_GLOBALS.cpp"                                
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/electron/darkOrange/darkOrange_GLOBALS.cpp"                                   
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/plastic/hardGreyPlastic/hardGreyPlastic_GLOBALS.cpp"                                 
                                //===========================================================================================                                   
                                #include "_SHADERS/plastic/dullPlastic/dullPlastic_GLOBALS.cpp"                                     
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/plastic/plasticBackLit/plasticBackLit_GLOBALS.cpp"                                    
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/plastic/frostyPlastic/frostyPlastic_GLOBALS.cpp"                                   
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/plastic/glowingPlastic/glowingPlastic_GLOBALS.cpp"                                     
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/velvet/velvet_GLOBALS.cpp"                                     
                                //---------------------------------------------------------------------------------                                 
                                #include "_SHADERS/plastic/shinyPlasticCellShade/shinyPlasticCellShade_GLOBALS.cpp"                                     
                                //---------------------------------------------------------------------------------                                   
                                #include "_SHADERS/plastic/shinyPlastic_04/shinyPlastic_04_GLOBALS.cpp"                                     
                                //---------------------------------------------------------------------------------                                   
                                #include "_SHADERS/plastic/shinyPlasticInverse/shinyPlasticInverse_GLOBALS.cpp"                                     
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/plastic/shinyPlasticFireBall/shinyPlasticFireBall_GLOBALS.cpp"                                     
                                //---------------------------------------------------------------------------------                               
                                #include "_SHADERS/plastic/shinyPlastic_05/shinyPlastic_05_GLOBALS.cpp"                                   
                                //===========================================================================================                                 
                                #include "_SHADERS/liquidShiny/liquidShiny_01/liquidShiny_01_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------    
                                #include "_SHADERS/liquidShiny/liquidShiny_02/liquidShiny_02_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                
                                #include "_SHADERS/liquidShiny/liquidShiny_03/liquidShiny_03_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                   
                                #include "_SHADERS/liquidShiny/liquidShiny_04/liquidShiny_04_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                
                                #include "_SHADERS/liquidShiny/liquidShiny_05/liquidShiny_05_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                   
                                #include "_SHADERS/plastic/rubber/rubber_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                 
                                #include "_SHADERS/plastic/rubber/rubber_20bit_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                        

                                #include "_SHADERS/CUBE_MAPPING/refraction/refraction_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                                              
                                #include "_SHADERS/CUBE_MAPPING/reflection/reflection_GLOBALS.cpp"                                  
                                //---------------------------------------------------------------------------------                                                              
                                #include "_SHADERS/CUBE_MAPPING/chromatic_dispersion/chromatic_dispersion_GLOBALS.cpp"                                                                 
                                //---------------------------------------------------------------------------------                                
                                #include "_SHADERS/CUBE_MAPPING/chromatic_dispersion_2/chromatic_dispersion_2_GLOBALS.cpp"                                
                                //---------------------------------------------------------------------------------                                   
                                                               
                                //===========================================================================================                                  
                                #include "_SHADERS/aniso/renderMonkeyish_A/renderMonkeyish_A_GLOBALS.cpp"  
                                //--------------------------------------------------------------------------------- 
                                #include "_SHADERS/aniso/renderMonkeyish_B/renderMonkeyish_B_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                 
                                #include "_SHADERS/aniso/renderMonkeyish_C/renderMonkeyish_C_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------  
                                #include "_SHADERS/aniso/renderMonkeyish_D/renderMonkeyish_D_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/aniso/renderMonkeyish_E/renderMonkeyish_E_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/aniso/renderMonkeyish_F/renderMonkeyish_F_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                 
                                #include "_SHADERS/aniso/renderMonkeyish_G/renderMonkeyish_G_GLOBALS.cpp"                                                                 
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/aniso/renderMonkeyish_H/renderMonkeyish_H_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/aniso/renderMonkeyish_I/renderMonkeyish_I_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                  
                                #include "_SHADERS/aniso/renderMonkeyish_J/renderMonkeyish_J_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                
                                #include "_SHADERS/metal/aluminum/aluminum_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                   
                                var         wood_B_ATTENUATION            =  0.417998;
                                #include "_SHADERS/wood/wood_B/wood_B_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                   
                                #include "_SHADERS/minnaert/minnaert_A/minnaert_A_SHADER_GLOBALS.cpp"  
                                //---------------------------------------------------------------------------------                                   
                                #include "_SHADERS/minnaert/sancho_qshaderedit_minnaertWard/sancho_qshaderedit_minnaertWard_SHADER_GLOBALS.cpp"  
                                //--------------------------------------------------------------------------------- 
                                
                                
                                //===========================================================================================                                 
                                
                                
                                //===========================================================================================                                 
                                //######################################################################################################________MODELS   
                                //######################################################################################################________MODELS                                                                                                
                                //------------------------------------------------------------------------------------   
                                #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/sculptris/sculptris_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/sphere/sphere_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/spiralGear/spiralGear_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/knight/knight_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/torus/torus_Globals.cpp"                                                                
                                //====================================================================================                                          
                                #include "_MODEL_FOLDERS_/diamond/diamond_Globals.cpp"  
                                //====================================================================================    
                                //#include "_MODEL_FOLDERS_/backWall_2x2/backWall_2x2_Globals.cpp"                                                          
                                //====================================================================================                                               



//======================================================================================================================================================================================


          
          
//###################################################################################################################################################
//###################################################################################################################################################
//###################################################################################################################################################

var shaderNumber = 0;

void SelectShader(var shaderNumber)
{    
        //--------------------------------------------------------------------------------------
        if(shaderNumber == 1)
        {
            #include "_SHADERS/fresnel/firstCopper/firstCopper_RENDER.cpp"        
        }
        //--------------------------------------------------------------------------------------
        if(shaderNumber == 2)
        {    
            #include "_SHADERS/fresnel/copper/copper_RENDER.cpp"  
        }
        //--------------------------------------------------------------------------------------
        if(shaderNumber == 3)
        {    
            #include "_SHADERS/electron/blue/blueElectron_RENDER.cpp"     
        }
        //--------------------------------------------------------------------------------------   
        if(shaderNumber == 4)
        {    
            #include "_SHADERS/fresnel/carbonFiber/carbonFiber_RENDER.cpp"     
        }
        //--------------------------------------------------------------------------------------     
        if(shaderNumber == 5)
        {    
            #include "_SHADERS/electron/grey/greyElectron_RENDER.cpp"       
        }
        //--------------------------------------------------------------------------------------    
        if(shaderNumber == 6)
        {    
            #include "_SHADERS/fresnel/bronze/bronze_RENDER.cpp"                                 
        }
        //--------------------------------------------------------------------------------------        
        if(shaderNumber == 7)
        {    
            #include "_SHADERS/electron/brightOrange/brightOrange_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------       
        if(shaderNumber == 8)
        {    
            #include "_SHADERS/squishy/squishy_01/squishy_01_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------      
        if(shaderNumber == 9)
        {    
            #include "_SHADERS/electron/darkOrange/darkOrange_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------    
        if(shaderNumber == 10)
        {    
            #include "_SHADERS/plastic/hardGreyPlastic/hardGreyPlastic_RENDER.cpp"                                  
        }
        //============================================================================================================      
        if(shaderNumber == 11)
        {    
            #include "_SHADERS/plastic/dullPlastic/dullPlastic_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------             
        if(shaderNumber == 12)
        {    
            #include "_SHADERS/plastic/plasticBackLit/plasticBackLit_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------    
        if(shaderNumber == 13)
        {    
            #include "_SHADERS/plastic/frostyPlastic/frostyPlastic_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 14)
        {    
            #include "_SHADERS/plastic/glowingPlastic/glowingPlastic_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------  
        if(shaderNumber == 15)
        {    
            #include "_SHADERS/velvet/velvet_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------   
        if(shaderNumber == 16)
        {    
            #include "_SHADERS/plastic/shinyPlasticCellShade/shinyPlasticCellShade_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------    
        if(shaderNumber == 17)
        {    
            #include "_SHADERS/plastic/shinyPlastic_04/shinyPlastic_04_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------  
        if(shaderNumber == 18)
        {    
            #include "_SHADERS/plastic/shinyPlasticInverse/shinyPlasticInverse_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------      
        if(shaderNumber == 19)
        {    
            #include "_SHADERS/plastic/shinyPlasticFireBall/shinyPlasticFireBall_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------      
        if(shaderNumber == 20)
        {    
            #include "_SHADERS/plastic/shinyPlastic_05/shinyPlastic_05_RENDER.cpp"                                  
        }
        //============================================================================================================  
        if(shaderNumber == 21)
        {    
                #include "_SHADERS/liquidShiny/liquidShiny_01/liquidShiny_01_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 22)
        {    
                #include "_SHADERS/liquidShiny/liquidShiny_02/liquidShiny_02_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 23)
        {    
                #include "_SHADERS/liquidShiny/liquidShiny_03/liquidShiny_03_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 24)
        {    
                #include "_SHADERS/liquidShiny/liquidShiny_04/liquidShiny_04_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 25)
        {    
                #include "_SHADERS/liquidShiny/liquidShiny_05/liquidShiny_05_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 26)
        {    
                #include "_SHADERS/plastic/rubber/rubber_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 1000)
        {    
                #include "_SHADERS/plastic/rubber/rubber_20bit_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
#ifdef WIN32        
        if(shaderNumber == 27)
        {    
                 #include "_SHADERS/CUBE_MAPPING/refraction/refraction_RENDER.cpp"                                  
                                          
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 28)
        {    
                  #include "_SHADERS/CUBE_MAPPING/reflection/reflection_RENDER.cpp"                             
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 29)
        {    
                 #include "_SHADERS/CUBE_MAPPING/chromatic_dispersion/chromatic_dispersion_RENDER.cpp"                               
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 30)
        {    
                 #include "_SHADERS/CUBE_MAPPING/chromatic_dispersion_2/chromatic_dispersion_2_RENDER.cpp"                              
        }
#endif    
        //============================================================================================================ 
        if(shaderNumber == 31)
        {    
                #include "_SHADERS/aniso/renderMonkeyish_A/renderMonkeyish_A_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 32)
        {    
            #include "_SHADERS/aniso/renderMonkeyish_B/renderMonkeyish_B_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 33)
        {    
            #include "_SHADERS/aniso/renderMonkeyish_C/renderMonkeyish_C_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 34)
        {    
            #include "_SHADERS/aniso/renderMonkeyish_D/renderMonkeyish_D_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 35)
        {    
            #include "_SHADERS/aniso/renderMonkeyish_E/renderMonkeyish_E_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 36)
        {    
            #include "_SHADERS/aniso/renderMonkeyish_F/renderMonkeyish_F_RENDER.cpp"                                  
        }
        //--------------------------------------------------------------------------------------     
        if(shaderNumber == 37)
        {    
            #include "_SHADERS/aniso/renderMonkeyish_G/renderMonkeyish_G_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 38)
        {    
            #include "_SHADERS/aniso/renderMonkeyish_H/renderMonkeyish_H_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 39)
        {    
            #include "_SHADERS/aniso/renderMonkeyish_I/renderMonkeyish_I_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 40)
        {    
            #include "_SHADERS/aniso/renderMonkeyish_J/renderMonkeyish_J_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 41)
        {    
            #include "_SHADERS/metal/aluminum/aluminum_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 42)
        {    
            #include "_SHADERS/wood/wood_B/wood_B_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 43)
        {    
            #include "_SHADERS/minnaert/minnaert_A/minnaert_A_SHADER_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 
        if(shaderNumber == 44)
        {    
            #include "_SHADERS/minnaert/sancho_qshaderedit_minnaertWard/sancho_qshaderedit_minnaertWard_SHADER_RENDER.cpp"                                  
        }
        //-------------------------------------------------------------------------------------- 



}

//###################################################################################################################################################
//###################################################################################################################################################
//###################################################################################################################################################

void InitGL( void )//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___BEGIN_INIT__
{
     
        eyePosition[0]                     =   0.0; 
        eyePosition[1]                     =   0.0; 
        eyePosition[2]                     =   0.0;

        look_LEFT_RIGHT                    =   0.0;
        look_UP_DOWN                       =   0.0;
        
        //==========================================================================
        #ifdef WIN32 
            #include "cpp/setPixelFormat.cpp"
            #include "headerFiles/glext_Init_B.cpp" 
            //-------------------------------------
            SetVSyncState(true);        
        #endif
        
//==========================================================================================================================================================================


	glGenTextures(1, &m_uiShadowMapTexture);
	glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        
	// Create the depth texture.
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, NULL);
        
	// Set the textures parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //-------------------------------------
	glGenFramebuffers(1, &m_uiFrameBufferObject);
	glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
        
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);     
        
        glBindFramebuffer(GL_FRAMEBUFFER, 0);        
//==========================================================================================================================================================================

       
        
     
        //===========================================================================================         
        #include "_SHADERS/fresnel/firstCopper/firstCopper_INIT.cpp"          
        //-----------------------------------------------------------------------------         
        #include "_SHADERS/fresnel/copper/copper_INIT.cpp"          
        //-----------------------------------------------------------------------------        
        #include "_SHADERS/electron/blue/blueElectron_INIT.cpp"
        //-----------------------------------------------------------------------------       
        #include "_SHADERS/fresnel/carbonFiber/carbonFiber_INIT.cpp"   
        //-----------------------------------------------------------------------------       
        #include "_SHADERS/electron/grey/greyElectron_INIT.cpp"          
        //-----------------------------------------------------------------------------       
        #include "_SHADERS/fresnel/bronze/bronze_INIT.cpp"         
        //-----------------------------------------------------------------------------
        #include "_SHADERS/electron/brightOrange/brightOrange_INIT.cpp"                                  
        //-----------------------------------------------------------------------------
        #include "_SHADERS/squishy/squishy_01/squishy_01_INIT.cpp"                                             
        //-----------------------------------------------------------------------------
        #include "_SHADERS/electron/darkOrange/darkOrange_INIT.cpp"          
        //-----------------------------------------------------------------------------
        #include "_SHADERS/plastic/hardGreyPlastic/hardGreyPlastic_INIT.cpp"          
        //=========================================================================================== 
        #include "_SHADERS/plastic/dullPlastic/dullPlastic_INIT.cpp"           
        //-----------------------------------------------------------------------------
        #include "_SHADERS/plastic/plasticBackLit/plasticBackLit_INIT.cpp"           
        //-----------------------------------------------------------------------------
        #include "_SHADERS/plastic/frostyPlastic/frostyPlastic_INIT.cpp"           
        //-----------------------------------------------------------------------------
        #include "_SHADERS/plastic/glowingPlastic/glowingPlastic_INIT.cpp"          
        //-----------------------------------------------------------------------------
        #include "_SHADERS/velvet/velvet_INIT.cpp"           
        //-----------------------------------------------------------------------------
        #include "_SHADERS/plastic/shinyPlasticCellShade/shinyPlasticCellShade_INIT.cpp"          
        //-----------------------------------------------------------------------------
        #include "_SHADERS/plastic/shinyPlastic_04/shinyPlastic_04_INIT.cpp"            
        //-----------------------------------------------------------------------------
        #include "_SHADERS/plastic/shinyPlasticInverse/shinyPlasticInverse_INIT.cpp"             
        //-----------------------------------------------------------------------------
        #include "_SHADERS/plastic/shinyPlasticFireBall/shinyPlasticFireBall_INIT.cpp"           
        //-----------------------------------------------------------------------------
        #include "_SHADERS/plastic/shinyPlastic_05/shinyPlastic_05_INIT.cpp"         
        //=========================================================================================== 
        #include "_SHADERS/liquidShiny/liquidShiny_01/liquidShiny_01_INIT.cpp"          
        //-----------------------------------------------------------------------------        
        #include "_SHADERS/liquidShiny/liquidShiny_02/liquidShiny_02_INIT.cpp"          
        //-----------------------------------------------------------------------------         
        #include "_SHADERS/liquidShiny/liquidShiny_03/liquidShiny_03_INIT.cpp"          
        //-----------------------------------------------------------------------------         
        #include "_SHADERS/liquidShiny/liquidShiny_04/liquidShiny_04_INIT.cpp"          
        //-----------------------------------------------------------------------------         
        #include "_SHADERS/liquidShiny/liquidShiny_05/liquidShiny_05_INIT.cpp"          
        //-----------------------------------------------------------------------------        
        #include "_SHADERS/plastic/rubber/rubber_INIT.cpp"          
        //-----------------------------------------------------------------------------          
        #include "_SHADERS/plastic/rubber/rubber_20bit_INIT.cpp"          
        //-----------------------------------------------------------------------------          
#ifdef WIN32
        #include "_SHADERS/CUBE_MAPPING/refraction/refraction_INIT.cpp"          
        //-----------------------------------------------------------------------------          
         #include "_SHADERS/CUBE_MAPPING/reflection/reflection_INIT.cpp"        
        //-----------------------------------------------------------------------------         
         #include "_SHADERS/CUBE_MAPPING/chromatic_dispersion/chromatic_dispersion_INIT.cpp"        
        //-----------------------------------------------------------------------------         
         #include "_SHADERS/CUBE_MAPPING/chromatic_dispersion_2/chromatic_dispersion_2_INIT.cpp"         
        //-----------------------------------------------------------------------------         
#endif   
        //===========================================================================================        
        #include "_SHADERS/aniso/renderMonkeyish_A/renderMonkeyish_A_INIT.cpp"           
        //-----------------------------------------------------------------------------           
        #include "_SHADERS/aniso/renderMonkeyish_B/renderMonkeyish_B_INIT.cpp"           
        //-----------------------------------------------------------------------------          
        #include "_SHADERS/aniso/renderMonkeyish_C/renderMonkeyish_C_INIT.cpp"           
        //-----------------------------------------------------------------------------          
        #include "_SHADERS/aniso/renderMonkeyish_D/renderMonkeyish_D_INIT.cpp"           
        //-----------------------------------------------------------------------------           
        #include "_SHADERS/aniso/renderMonkeyish_E/renderMonkeyish_E_INIT.cpp"           
        //-----------------------------------------------------------------------------          
        #include "_SHADERS/aniso/renderMonkeyish_F/renderMonkeyish_F_INIT.cpp"           
        //-----------------------------------------------------------------------------          
        #include "_SHADERS/aniso/renderMonkeyish_G/renderMonkeyish_G_INIT.cpp"           
        //-----------------------------------------------------------------------------           
        #include "_SHADERS/aniso/renderMonkeyish_H/renderMonkeyish_H_INIT.cpp"           
        //-----------------------------------------------------------------------------          
        #include "_SHADERS/aniso/renderMonkeyish_I/renderMonkeyish_I_INIT.cpp"           
        //-----------------------------------------------------------------------------          
        #include "_SHADERS/aniso/renderMonkeyish_J/renderMonkeyish_J_INIT.cpp"           
        //===========================================================================================        
        #include "_SHADERS/metal/aluminum/aluminum_INIT.cpp"           
        //-----------------------------------------------------------------------------           
        #include "_SHADERS/wood/wood_B/wood_B_INIT.cpp"           
        //-----------------------------------------------------------------------------           
        #include "_SHADERS/minnaert/minnaert_A/minnaert_A_SHADER_INIT.cpp"           
        //-----------------------------------------------------------------------------    
        #include "_SHADERS/minnaert/sancho_qshaderedit_minnaertWard/sancho_qshaderedit_minnaertWard_SHADER_INIT.cpp"           
        //-----------------------------------------------------------------------------    
                
        
        //-----------------------------------------------------------------------------         
        //######################################################################################################________MODELS   
        //######################################################################################################________MODELS            
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Init.cpp"                                                                   
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/sculptris/sculptris_Init.cpp"                                                                   
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/sphere/sphere_Init.cpp"                                                                   
        //====================================================================================    
        #include "_MODEL_FOLDERS_/spiralGear/spiralGear_Init.cpp"                                                                   
        //====================================================================================   
        #include "_MODEL_FOLDERS_/knight/knight_Init.cpp"                                                                   
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/torus/torus_Init.cpp" 
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/diamond/diamond_Init.cpp"                                                                   
        //====================================================================================                                          
        //#include "_MODEL_FOLDERS_/backWall_2x2/backWall_2x2_Init.cpp"                                                             
        //====================================================================================                                                   
       
                               
                                    
          
//=================================================================================================================== 
#ifdef _WIN32
        #include "cubeMaps/cubeMap_INIT.cpp"  
#endif


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);	
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);  


//=====================================================================================================================

    



}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@___END_INIT__



//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################


void RenderGL(void)
{
        

        
        
        
        
        
        
//##################################################################################################################################################################################################        
//##################################################################################################################################################################################################         
//##################################################################################################################################################################################################         
//##################################################################################################################################################################################################          
        
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //========================================================================================================================================================        
        #ifdef __APPLE__    
            glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
        #endif    
        //========================================================================================================================================================        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!        
        //---------------------------------------------------RETURN_TO_MAIN_FRAMEBUFFER____________________!!!!!!!!!!!!!!!!!!!!!!!!!!!!          
        //========================================================================================================================================================



        //=========================================================================================================================================================    
        glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
        //----------------------------------------------------------------------------------
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        PerspectiveMatrix(projection, 35,viewWidth / viewHeight, 0.1, 1000);
        //=========================================================================================================================================================
        #ifdef __APPLE__
        Rotate(projection, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        projection[12] = eyePosition[1];
        projection[13] = eyePosition[0];
        projection[15] = eyePosition[2];        
        #endif        
        //=========================================================================================================================================================        
        #ifdef WIN32        
        projection[12] = eyePosition[0];
        projection[13] = eyePosition[1];
        projection[15] = eyePosition[2];
        #endif
        
        Rotate(projection, 1.0, 0.0, 0.0,  look_UP_DOWN);
        Rotate(projection, 0.0, 1.0, 0.0, -look_LEFT_RIGHT);        
        
//#################################################################################################################################################################        
spinModel            += 1.0;
spiralGear_ROTATE[3] += 1.0;
knight_ROTATE[3]     += 1.0;
//==============================================================================================================

/*
aluminum_LIGHT_POSITION_01[0] += velocity[0];
aluminum_LIGHT_POSITION_01[1] += velocity[1];
aluminum_LIGHT_POSITION_01[2] += velocity[2];

//========================================================
if(aluminum_LIGHT_POSITION_01[0] >= 200.00)
{
    velocity[0] *= -1.0;                               
}
//---------------------------------------
if(aluminum_LIGHT_POSITION_01[0] <= -200.00)
{
    velocity[0] *= -1.0;                               
}
//-------------------------------------------------------
if(aluminum_LIGHT_POSITION_01[1] >= 100.00)
{
    velocity[1] *= -1.0;                               
}
//---------------------------------------
if(aluminum_LIGHT_POSITION_01[1] <=-100.00)
{
    velocity[1] *= -1.0;                               
}
//-------------------------------------------------------
if(aluminum_LIGHT_POSITION_01[2] >= 200.00)
{
    velocity[2] *= -1.0;                               
}
//---------------------------------------
if(aluminum_LIGHT_POSITION_01[2] <= -200.00)
{
    velocity[2] *= -1.0;                               
}
//========================================================
*/

        groupSelection = changeSet;

if(groupSelection == 1)
{
        #include "frame_01.cpp"
}

if(groupSelection == 2)
{
        #include "frame_02.cpp"
}

if(groupSelection == 3)
{
        #include "frame_03.cpp"
}

if(groupSelection == 4)
{      
       #include "frame_04.cpp"
}      

if(groupSelection == 5)
{      
        #include "frame_05.cpp"
} 
        


}//_END_RenderGL()


//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
#ifdef WIN32

void ProcessKeyboard(void)
{
   
       
    //=======================================================================================                                           
	                                                                                                                                  
    if (keys['L'])                                                                                                                      
    {	                                                                                                                                  
             SET_01_POSITION[0]         +=  0.1;                                                                            
    }                                                                                                                                   
    if (keys['J'])                                                                                                                   
    {                                                                                                                                   
             SET_01_POSITION[0]         -=  0.1;                                                                         
    }    
    if (keys['I'])                                                                                                                      
    {	                                                                                                                                  
             SET_01_POSITION[1]         +=  0.1;                                                                            
    }	                                                                                                                                  
    if (keys['K'])                                                                                                                      
    {	                                                                                                                                  
             SET_01_POSITION[1]         -=  0.1;                                                                            
    }                                                                                                                                   
    if (keys['O'])                                                                                                                      
    {	                                                                                                                                  
             SET_01_POSITION[2]         +=  0.1;                                                                            
    }	                                                                                                                                  
    if (keys['U'])                                                                                                                      
    {	                                                                                                                                  
             SET_01_POSITION[2]         -=  0.1;      
    }
    //=======================================================================================        
 
    if (keys['M'])                                                                                                                      
    {	                                                                                                                                  
             renderMonkeyish_G_ATTENUATION                  +=  0.01;                                                                            
    }	                                                                                                                                  
    if (keys['N'])                                                                                                                      
    {	                                                                                                                                  
             renderMonkeyish_G_ATTENUATION                  -=  0.01;                                                                            
    }  
    if (keys['X'])                                                                                                                      
    {	                                                                                                                                  
             renderMonkeyish_I_NOISE_SCALE                    +=  0.0001;                                                                            
    }	                                                                                                                                  
    if (keys['Z'])                                                                                                                      
    {	                                                                                                                                  
             renderMonkeyish_I_NOISE_SCALE                    -=  0.0001;                                                                            
    }        
  
  
    if (keys['V'])                                                                                                                      
    {	                                                                                                                                  
             minnaert_A_GENERIC                    +=  .11;                                                                            
    }	                                                                                                                                  
    if (keys['C'])                                                                                                                      
    {	                                                                                                                                  
             minnaert_A_GENERIC                    -=  .11;                                                                            
    }   
  
   //==============================================================================
/*    if (keys['C'] && KEY_C_IS_RESET && !keys[VK_SHIFT])                                                                                                                      
    {	                                                                                                                                  
            stepVBOcount                    -=  10; 
            KEY_C_IS_RESET                    = false;                                                                           
    }	                                                                                                                                  
    if (!keys['C'])                                                                                                                      
    {	                                                                                                                                  
            KEY_C_IS_RESET                    = true;                                                                           
    } 
    //-----------------------------------------------------------------------------   
    if (keys['V'] && KEY_V_IS_RESET && !keys[VK_SHIFT])                                                                                                                      
    {	                                                                                                                                  
            stepVBOcount                    +=  10;
            KEY_V_IS_RESET                    = false;                                                                            
    }             
    if (!keys['V'])                                                                                                                      
    {	                                                                                                                                  
            KEY_V_IS_RESET                    = true;                                                                           
    } 
*/    //-----------------------------------------------------------------------------    
   //==============================================================================
       //----------------------------------------------
       if(keys[VK_F8])
       {
             ofstream outSettings("settings.cpp");
             
             outSettings << "var         SET_01_POSITION[]    =  {"   << SET_01_POSITION[0] << ", "
                                                                                 << SET_01_POSITION[1] << ", "
                                                                                 << SET_01_POSITION[2] << ", 1.0};\n\n";            
            
            
            
             outSettings << "var         renderMonkeyish_I_NOISE_SCALE            =  " << renderMonkeyish_I_NOISE_SCALE << ";\n";
             outSettings << "var         aluminum_SHININESS              =  " << aluminum_SHININESS << ";\n";             
             outSettings << "var         minnaert_A_GENERIC   =  " << minnaert_A_GENERIC << ";\n\n\n";             
            
             //------------------------------------------------------------------------------------------------------------------------------
             
             outSettings << "          eyePosition[0]    =  "       << eyePosition[0] << ";\n";
             outSettings << "          eyePosition[1]    =  "       << eyePosition[1] << ";\n";
             outSettings << "          eyePosition[2]    =  "       << eyePosition[2] << ";\n";               
             //------------------------------------------------------------------------------------------------------------------------------      
      
      
      
      
       }
       //----------------------------------------------      
     
    //=======================================================================================                                           
    //=======================================================================================
    
    //=======================================================================================
    if (keys[VK_TAB] && TAB_KEY_RESET && !keys[VK_SHIFT])
    {
             changeSet         +=  1;
             TAB_KEY_RESET                  = false;
    }
    if (!keys[VK_TAB])
    {
            TAB_KEY_RESET                 = true;
    }

    if (keys[VK_TAB] && TAB_KEY_RESET && keys[VK_SHIFT])
    {
             changeSet         -=  1;
             TAB_KEY_RESET           = false;
    }
    if (!keys[VK_TAB])
    {
            TAB_KEY_RESET           = true;
    }
    //=======================================================================================
   
    //=======================================================================================
    
    
    //=======================================================================================     
    if (keys['A'])                                                                                                                   
    {                                                                                                                                   
             moveSet[0]         -=  0.1;                                                                         
    }	                                                                                                                                  
    if (keys['D'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[0]         +=  0.1;                                                                            
    }                                                                                                                                   
    if (keys['W'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[1]         +=  0.1;                                                                            
    }	                                                                                                                                  
    if (keys['S'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[1]         -=  0.1;                                                                            
    }                                                                                                                                   
    if (keys['E'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[2]         +=  0.1;                                                                            
    }	                                                                                                                                  
    if (keys['Q'])                                                                                                                      
    {	                                                                                                                                  
             moveSet[2]         -=  0.1;      
    }
    //=======================================================================================        
     
}//_END_ProcessKeyboard()

#endif

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################



void shutDownGL( void )
{

        
        //====================================================================================   
        #include "_SHADERS/minnaert/minnaert_A/minnaert_A_SHADER_SHUTDOWN.cpp"                          
    
        //====================================================================================   
        #include "_MODEL_FOLDERS_/flowerShield/flowerShield_Shutdown.cpp"                                                               
        //====================================================================================            
/*        #include "_MODEL_FOLDERS_/sculptris/sculptris_Shutdown.cpp"                                                               
        //====================================================================================               
        #include "_MODEL_FOLDERS_/sphere/sphere_Shutdown.cpp"                                                               
        //====================================================================================                                          
        #include "_MODEL_FOLDERS_/spiralGear/spiralGear_Shutdown.cpp"                                                               
        //====================================================================================                 
        #include "_MODEL_FOLDERS_/knight/knight_Shutdown.cpp"                                                               
        //====================================================================================   
        #include "_MODEL_FOLDERS_/torus/torus_Shutdown.cpp"                                                                 
        //====================================================================================    
        #include "_MODEL_FOLDERS_/capsule/capsule_Shutdown.cpp"                                                               
        //====================================================================================    
*/
     
}


//===================================================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===================================================================================================================================================================




