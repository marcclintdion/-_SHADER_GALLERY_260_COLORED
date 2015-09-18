glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
glEnable(GL_TEXTURE_CUBE_MAP);
 glGenTextures(1, &cubemapTexture[0]);  
    glBindTexture(GL_TEXTURE_CUBE_MAP,  cubemapTexture[0]);

    char textName_POSX[] = "cubeMaps/Terrain_posx.png";	
    char textName_NEGX[] = "cubeMaps/Terrain_negx.png";	
    char textName_POSY[] = "cubeMaps/Terrain_posy.png";    
    char textName_NEGY[] = "cubeMaps/Terrain_negy.png";	
    char textName_POSZ[] = "cubeMaps/Terrain_posz.png";	
    char textName_NEGZ[] = "cubeMaps/Terrain_negz.png";    
    

    
    
    FREE_IMAGE_FORMAT fifmt;
    FIBITMAP *dib;
    FIBITMAP *temp = dib;    
    
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_POSX, 0);
    dib = FreeImage_Load(fifmt,   textName_POSX, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_NEGX, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGX, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_POSY, 0);
    dib = FreeImage_Load(fifmt,   textName_POSY, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_NEGY, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGY, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}

    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_POSZ, 0);
    dib = FreeImage_Load(fifmt,   textName_POSZ, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_NEGZ, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGZ, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dib);
	}


    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER,    GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER,    GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S,        GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T,        GL_CLAMP_TO_EDGE);    
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_GENERATE_MIPMAP_SGIS,  GL_TRUE );    

/*    
    glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S,             GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T,             GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_R,             GL_CLAMP_TO_EDGE );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MIN_FILTER,         GL_LINEAR_MIPMAP_LINEAR );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAG_FILTER,         GL_LINEAR );
	glTexParameteri( GL_TEXTURE_CUBE_MAP_ARB, GL_GENERATE_MIPMAP_SGIS,       GL_TRUE );
	glTexParameterf( GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16.0);   
*/

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
/*

    glBindTexture(GL_TEXTURE_CUBE_MAP,  dark_cubemapTexture[0]);
    
    char dark_POSX[] = "cubeMaps/opensea/opensea_positive_x.png";	
    char dark_NEGX[] = "cubeMaps/opensea/opensea_negative_x.png";	
    char dark_POSY[] = "cubeMaps/opensea/opensea_positive_y.png";    
    char dark_NEGY[] = "cubeMaps/opensea/opensea_negative_y.png";	
    char dark_POSZ[] = "cubeMaps/opensea/opensea_positive_z.png";	
    char dark_NEGZ[] = "cubeMaps/opensea/opensea_negative_z.png";    

    
    FREE_IMAGE_FORMAT dark_fifmt;
    FIBITMAP *dark_dib;
    FIBITMAP *dark_temp = dark_dib;    
    
    //------------------------------------------------------------------------------------------
    
    dark_fifmt = FreeImage_GetFileType(dark_POSX, 0);
    dark_dib = FreeImage_Load(dark_fifmt,   dark_POSX, 0);
    dark_temp = dark_dib;
    
    dark_dib = FreeImage_ConvertTo32Bits(dark_temp);
    FreeImage_Unload(dark_temp);	 
	
    if( dark_dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dark_dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dark_dib), FreeImage_GetHeight(dark_dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dark_dib);
	}
    //------------------------------------------------------------------------------------------
    
    dark_fifmt = FreeImage_GetFileType(dark_NEGX, 0);
    dark_dib = FreeImage_Load(dark_fifmt,   dark_NEGX, 0);
    dark_temp = dark_dib;
    
    dark_dib = FreeImage_ConvertTo32Bits(dark_temp);
    FreeImage_Unload(dark_temp);	 
	
    if( dark_dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dark_dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dark_dib), FreeImage_GetHeight(dark_dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dark_dib);
	}
    //------------------------------------------------------------------------------------------
    
    dark_fifmt = FreeImage_GetFileType(dark_POSY, 0);
    dark_dib = FreeImage_Load(dark_fifmt,   dark_POSY, 0);
    dark_temp = dark_dib;
    
    dark_dib = FreeImage_ConvertTo32Bits(dark_temp);
    FreeImage_Unload(dark_temp);	 
	
    if( dark_dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dark_dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dark_dib), FreeImage_GetHeight(dark_dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dark_dib);
	}
    //------------------------------------------------------------------------------------------
    
    dark_fifmt = FreeImage_GetFileType(dark_NEGY, 0);
    dark_dib = FreeImage_Load(dark_fifmt,   dark_NEGY, 0);
    dark_temp = dark_dib;
    
    dark_dib = FreeImage_ConvertTo32Bits(dark_temp);
    FreeImage_Unload(dark_temp);	 
	
    if( dark_dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dark_dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dark_dib), FreeImage_GetHeight(dark_dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dark_dib);
	}

    //------------------------------------------------------------------------------------------
    
    dark_fifmt = FreeImage_GetFileType(dark_POSZ, 0);
    dark_dib = FreeImage_Load(dark_fifmt,   dark_POSZ, 0);
    dark_temp = dark_dib;
    
    dark_dib = FreeImage_ConvertTo32Bits(dark_temp);
    FreeImage_Unload(dark_temp);	 
	
    if( dark_dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dark_dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dark_dib), FreeImage_GetHeight(dark_dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dark_dib);
	}
    //------------------------------------------------------------------------------------------
    
    dark_fifmt = FreeImage_GetFileType(dark_NEGZ, 0);
    dark_dib = FreeImage_Load(dark_fifmt,   dark_NEGZ, 0);
    dark_temp = dark_dib;
    
    dark_dib = FreeImage_ConvertTo32Bits(dark_temp);
    FreeImage_Unload(dark_temp);	 
	
    if( dark_dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dark_dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dark_dib), FreeImage_GetHeight(dark_dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        free(pixels);
        FreeImage_Unload(dark_dib);
	}


    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER,    GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER,    GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S,        GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T,        GL_CLAMP_TO_EDGE);    
	//glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_GENERATE_MIPMAP_SGIS,  GL_TRUE );    

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
*/
